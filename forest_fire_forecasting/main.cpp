#include <iostream>
#include "SocketClient.h"
#include "TemperatureSensor.h"
#include <chrono>
#include <thread>

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


using namespace std;

string generateRandomPayload()
{
    srand(time(0));
    int stime = rand();
    int temp = (rand() % 100) + 20;
    return "34," + std::to_string(stime)+","+std::to_string(temp);
}

void sendEachSecond(TemperatureSensor *temperatureSensor, SocketClient *con,
                        int *clients, int *sd)
{
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // sleep for 1 second
    }
}

int main(){
    int connection_status=-1, sock=-1, port = 5000, addrlen, activity,
                              max_sd, sd, new_socket, connected_clients=0;

    //PayloadReceiver payRec;
    SocketClient con(port);
    //TemperatureSensor temperatureSensor;

    sock=con.establishCon();
    if(sock == 0)
    {
        cout<< "Failed to create socket!"<<endl;
        return sock;
    }

    con.address.sin_family = AF_INET;
    con.address.sin_addr.s_addr = INADDR_ANY;
    con.address.sin_port = htons(port);

    connection_status = connect(con.sock,
                                (struct sockaddr*)&(con.address),
                                sizeof(con.address));

    if (connection_status < 0)
    {
        cout<< "error: cannot connect to server on port: "<<port<<endl;
        return -4;
    }

    int valread=0;    char buffer[1024] = { 0 };
    /* listen on port */
    while(true)
    {
        //wait for an activity on one of the sockets , timeout is NULL ,
        //so wait indefinitely
        if(valread==0){
            valread = read(con.sock, buffer, 1024);
            cout<<buffer<<"\n";

            std::fill( std::begin( buffer ), std::end( buffer), 0 );
//            std::fill(buffer.begin(),buffer.end(),0);
            //std::fill_n(buffer, 1024, 0);
        }
        valread=0;
    }


    return 0;
}
