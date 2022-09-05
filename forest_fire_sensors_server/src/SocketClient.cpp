#include "SocketClient.h"

SocketClient::SocketClient(int port)
{
    SocketClient::port = port;
}

int SocketClient::establishCon()
{
    SocketClient::sock = socket(AF_INET, SOCK_STREAM, 0);
    if(SocketClient::sock <= 0)
        return -3;
    return SocketClient::sock ;
}

void SocketClient::recieveSensorData()
{
    SocketClient::port = port;
}
void SocketClient::sendData(){}

void SocketClient::sendData(int *clients, int *sd, char* data)
{
    //else its some IO operation on some other socket
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        *sd = clients[i];
        if (FD_ISSET( *sd, &(SocketClient::readfds)))
        {
            //Check if it was for closing , and also read the
            //incoming message
            if ((SocketClient::valread = read( *sd, buffer, 1024)) == 0)
            {
                //Somebody disconnected , get his details and print
                getpeername(*sd, (struct sockaddr*)&(SocketClient::address), \
                            (socklen_t*)&(SocketClient::addrlen));
                //Close the socket and mark as 0 in list for reuse
                close( *sd );
                clients[i] = 0;
                continue;
            }
        }
        send(*sd, data, strlen(data), 0);
    }

}

void SocketClient::sendData(int *clients, int *sd, char *data, int*addrlen)
{
    int valread;
    char buffer[1024];
    cout<<"data\n:client: "<<clients[0]<<"\nSocket descriptor:"
        << *sd<<"\nPayload: "<<data<<"\nAddrlen: "<<*addrlen<<"\nMAX_Clients:"<<MAX_CLIENTS<<"\n";

    cout<<"Sending data\n";
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        *sd = clients[i];

        if (FD_ISSET( *sd, &(SocketClient::readfds)))
        {
            //Check if it was for closing , and also read the
            //incoming message
            if ((valread = read( *sd, buffer, 1024)) == 0)
            {
                //Somebody disconnected , get his details and print
                getpeername(*sd, (struct sockaddr*)&(SocketClient::address), \
                            (socklen_t*)&addrlen);
                printf("Host disconnected , ip %s , port %d \n",
                       inet_ntoa(SocketClient::address.sin_addr), ntohs(SocketClient::address.sin_port));
                //Close the socket and mark as 0 in list for reuse
                close( *sd );
                clients[i] = 0;
            }

            //Echo back the message that came in
            else
            {
                //set the string terminating NULL byte on the end
                //of the data read
                data[valread] = '\0';
                cout<<"Sending this data:"<<data<<"\n";
                send(*sd, data, strlen(data), 0 );
            }
        }
    }
    //}
}
