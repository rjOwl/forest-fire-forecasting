#include "SocketClient.h"

SocketClient::SocketClient(int port)
{
    SocketClient::port = port;
}
void SocketClient::recieveSensorData(){}

int SocketClient::establishCon()
{
    SocketClient::sock = socket(AF_INET, SOCK_STREAM, 0);
    if(SocketClient::sock <= 0)
        return -3;
    return SocketClient::sock ;
}

void SocketClient::sendData(){}

void SocketClient::sendData(int *clients, int *sd, char* data, int*connected_clients)
{
    //else its some IO operation on some other socket
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        *sd = clients[i];
        if(*connected_clients>0)
            send(*sd, data, strlen(data), 0);
    }
}
