#include <iostream>
#include "SocketClient.h"
#include "TemperatureSensor.h"
#include "PayloadReceiver.h"
#include <chrono>

#include <string>
#include <cstring>
#include <unistd.h>   //close
#include <arpa/inet.h>    //close
#include <sys/types.h>
#include <sys/socket.h>
#include <stdexcept>
#define TRUE   1
#define FALSE  0
#define PORT 8888
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

string generateRandomPayload()
{
    srand(time(0));
    int stime = rand();
    int temp = (rand() % 100) + 20;
    return "34," + std::to_string(stime)+","+std::to_string(temp);
}

void sendEachSecond(TemperatureSensor *temperatureSensor, SocketClient *con,
                    int *clients, int *sd, int* connected_clients)
{
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // sleep for 1 second
        temperatureSensor->parsePayload(generateRandomPayload());
        char temp[3];
        if(*connected_clients>0){
            strcpy(temp, temperatureSensor->getTemp().c_str());
            cout<<"Current temp: "<<temp<<"\n";
            cout<<"Current temp: "<<temperatureSensor->getTemp()<<"\n";
            cout<<"Payload: "<<generateRandomPayload()<<"\n";
            con->sendData(clients, sd, temp, connected_clients);
            std::fill( std::begin( temp ), std::end( temp ), 0 );
        }
    }
}
void addClients(TemperatureSensor *temperatureSensor, SocketClient *con,
                    int *clients, int *sd, int* connected_clients, int *sock, int *max_sd, int *activity,
                     int*new_socket, int* addrlen, int*client_established)
{
    char *msg= "Connection established to server!\n";

    while(true)
    {
        cout<<"Waiting for clients to connect\n";
        FD_ZERO(&(con->readfds));

        //add master socket to set
        FD_SET(*sock, &(con->readfds));
        *max_sd = *sock;

        //add child sockets to set
        for ( int i = 0 ; i < MAX_CLIENTS ; i++)
        {
            //socket descriptor
            *sd = clients[i];

            //if valid socket descriptor then add to read list
            if(*sd > 0)
                FD_SET( *sd, &(con->readfds));

            //highest file descriptor number, need it for the select function
            if(*sd > *max_sd)
                *max_sd = *sd;
        }


        //wait for an activity on one of the sockets , timeout is NULL ,
        //so wait indefinitely
        *activity = select( *max_sd + 1, &(con->readfds), NULL, NULL, NULL);
        // listen for incoming connections and add them to the array
        if ((*activity < 0) && (errno!=EINTR))
        {
            printf("select error");
        }

        //If something happened on the master socket ,
        //then its an incoming connection
        if (FD_ISSET(*sock, &(con->readfds)))
        {
            if ((*new_socket = accept(*sock,
                                        (struct sockaddr *)&(con->address), (socklen_t*)&(*addrlen)))<0)
            {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            //inform user of socket number - used in send and receive commands
            cout<<"New connection, socket fd is: "<<*new_socket<<", ip is:"<< inet_ntoa(con->address.sin_addr)<<
                ", port: "<<ntohs(con->address.sin_port)<<" \n";

            //send new connection greeting message
            if( send(*new_socket, msg, strlen(msg), 0) != strlen(msg) )
            {
                perror("send");
            }

            cout<<"Welcome message sent successfully"<<"\n";

            //add new socket to array of sockets
            for (int i = 0; i < MAX_CLIENTS; i++)
            {
                //if position is empty
                if( clients[i] == 0 )
                {
                    clients[i] = *new_socket;
                    *connected_clients++;
                    *client_established++;
                    cout<<"Adding new client list of sockets as: "<< i<<"\n";
                    cout<<"Current connected clients: "<< *connected_clients<<"\n";
                    break;
                }
            }
        }
    }
}
int main()
{
    int clients[MAX_CLIENTS], sock=-1, port = 5001, addrlen, activity,
                              max_sd, sd, new_socket, connected_clients=0, client_established=0;
    std::vector<std::thread> threads;
    PayloadReceiver payRec;
    SocketClient con(port);
    TemperatureSensor temperatureSensor;

    sock=con.establishCon();
    if(sock == 0)
    {
        cout<< "Failed to create socket!"<<endl;
        return sock;
    }
    for (int i=0; i < MAX_CLIENTS; i++)
        clients[i]=0;

    cout<< "create master socket: "<<sock<<endl;
    con.address.sin_family = AF_INET;
    con.address.sin_addr.s_addr = INADDR_ANY;
    con.address.sin_port = htons(port);

    if (bind(sock, (struct sockaddr *)&con.address, sizeof(con.address))<0)
    {
        cout<< "error: cannot bind socket to port: "<<port<<endl;
        return -4;
    }

    /* listen on port */
    //try to specify maximum of 5 pending connections for the master socket
    if (listen(sock, 3) < 0)
    {
        cout<< "error: cannot listen on port: %d!"<<port<<endl;
        return -5;
    }
    addrlen = sizeof(con.address);

    thread t1(sendEachSecond, &temperatureSensor, &con, clients, &sd, &connected_clients);
    char *msg= "Connection established to server!\n";
    cout<<"Waiting clients...";
 // Recieve new clients and add them to the client list
    while(true)
    {
        FD_ZERO(&(con.readfds));

        //add master socket to set
        FD_SET(sock, &(con.readfds));
        max_sd = sock;

        //add child sockets to set
        for ( int i = 0 ; i < MAX_CLIENTS ; i++)
        {
            //socket descriptor
            sd = clients[i];

            //if valid socket descriptor then add to read list
            if(sd > 0)
                FD_SET( sd, &(con.readfds));

            //highest file descriptor number, need it for the select function
            if(sd > max_sd)
                max_sd = sd;
        }


        //wait for an activity on one of the sockets , timeout is NULL ,
        //so wait indefinitely
        activity = select( max_sd + 1, &(con.readfds), NULL, NULL, NULL);
        // listen for incoming connections and add them to the array
        if ((activity < 0) && (errno!=EINTR))
        {
            printf("select error");
        }

        //If something happened on the master socket ,
        //then its an incoming connection
        if (FD_ISSET(sock, &(con.readfds)))
        {
            if ((new_socket = accept(sock,
                                     (struct sockaddr *)&(con.address), (socklen_t*)&addrlen))<0)
            {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            //inform user of socket number - used in send and receive commands
            cout<<"New connection, socket fd is: "<<new_socket<<", ip is:"<< inet_ntoa(con.address.sin_addr)<<
                ", port: "<<ntohs(con.address.sin_port)<<" \n";

            //send new connection greeting message
            if( send(new_socket, msg, strlen(msg), 0) != strlen(msg) )
            {
                perror("send");
            }

            cout<<"Welcome message sent successfully"<<"\n";

            //add new socket to array of sockets
            for (int i = 0; i < MAX_CLIENTS; i++)
            {
                //if position is empty
                if( clients[i] == 0 )
                {
                    clients[i] = new_socket;
                    connected_clients++;
                    cout<<"Adding new client list of sockets as: "<< i<<"\n";
                    break;
                }
            }
        }
   }
    // Recieve new clients and add them to the client list
//    thread t0(addClients, &temperatureSensor, &con, clients, &sd, &connected_clients, &sock, &max_sd, &activity,
//                     &new_socket, &addrlen, &client_established);
//                     t0.join();
//    thread t0(sendEachSecond, &temperatureSensor, &con, clients, &sd, &connected_clients);

//    t1.join();

//    threads.push_back(thread(addClients, &temperatureSensor, &con, clients, &sd, &connected_clients, &sock, &max_sd, &activity,
//                 &new_socket, &addrlen, &client_established));
//    threads.push_back(thread(sendEachSecond, &temperatureSensor, &con, clients, &sd, &connected_clients));

//    for(auto& thread : threads){
//        thread.join();
//    }
    return 0;
}

/**

while(TRUE)
{
    //clear the socket set
    FD_ZERO(&readfds);

    //add master socket to set
    FD_SET(master_socket, &readfds);
    max_sd = master_socket;

    //add child sockets to set
    for ( i = 0 ; i < max_clients ; i++)
    {
        //socket descriptor
        sd = client_socket[i];

        //if valid socket descriptor then add to read list
        if(sd > 0)
            FD_SET( sd , &readfds);

        //highest file descriptor number, need it for the select function
        if(sd > max_sd)
            max_sd = sd;
    }

    //wait for an activity on one of the sockets , timeout is NULL ,
    //so wait indefinitely
    activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);

    if ((activity < 0) && (errno!=EINTR))
    {
        printf("select error");
    }

    //If something happened on the master socket ,
    //then its an incoming connection
    if (FD_ISSET(master_socket, &readfds))
    {
        if ((new_socket = accept(master_socket,
                (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        //inform user of socket number - used in send and receive commands
        printf("New connection , socket fd is %d , ip is : %s , port : %d\n"
        , new_socket , inet_ntoa(address.sin_addr) , ntohs(address.sin_port));

        //send new connection greeting message
        if( send(new_socket, message, strlen(message), 0) != strlen(message) )
        {
            perror("send");
        }

        puts("Welcome message sent successfully");

        //add new socket to array of sockets
        for (i = 0; i < max_clients; i++)
        {
            //if position is empty
            if( client_socket[i] == 0 )
            {
                client_socket[i] = new_socket;
                printf("Adding to list of sockets as %d\n" , i);

                break;
            }
        }
    }

    //else its some IO operation on some other socket
    for (i = 0; i < max_clients; i++)
    {
        sd = client_socket[i];

        if (FD_ISSET( sd , &readfds))
        {
            //Check if it was for closing , and also read the
            //incoming message
            if ((valread = read( sd , buffer, 1024)) == 0)
            {
                //Somebody disconnected , get his details and print
                getpeername(sd , (struct sockaddr*)&address , \
                    (socklen_t*)&addrlen);
                printf("Host disconnected , ip %s , port %d \n" ,
                      inet_ntoa(address.sin_addr) , ntohs(address.sin_port));

                //Close the socket and mark as 0 in list for reuse
                close( sd );
                client_socket[i] = 0;
            }

            //Echo back the message that came in
            else
            {
                //set the string terminating NULL byte on the end
                //of the data read
                buffer[valread] = '\0';
                printf("Broadcasing message\n");
                for (int y = 0; y < max_clients; y++)
                {
                    if(y!=i){
                        sd2 = client_socket[y];
                        send(sd2, buffer , strlen(buffer) , 0);
                    }
                }
            }
        }
    }
}

Server logic:
-------------
clients should only access the server if the have the credintials
Thread1:
    while server is up then:
        it will listen to incoming connections
        if new connection then:
            if credentials valid then:
                add the client to the clientList
            else:
                don't add
Thread2:
while server is up:
    if there are connected clients then:
        server will loop through them and
        each 1 second server will send temperature to the clients
*/

