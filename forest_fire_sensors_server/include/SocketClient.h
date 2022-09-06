#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <iostream>
#include <INetworkClient.h>
#include <string>
#include <cstring>
#include <unistd.h>   //close
#include <arpa/inet.h>    //close
#include <sys/types.h>
#include <sys/socket.h>
#include <stdexcept>
#define TRUE   1
#define FALSE  0
#define MAX_CLIENTS 300

/**
Reference:
WORKED: https://stackoverflow.com/questions/9406580/c-undefined-reference-to-vtable-and-inheritance
https://www.programiz.com/cpp-programming/pure-virtual-funtion
*/
using namespace std;

class SocketClient : public INetworkClient{
    public:
        int sock, valread;
        struct sockaddr_in address;
        char buffer[1025];
        int addrlen;
        fd_set readfds;

//////////////////////////////////////

        SocketClient(int port);
//        ~SocketClient();
        int startListening();

        int establishCon();
        void recieveSensorData();
        void sendData();
        void sendData(int *, int *, char *, int*);
        int getPort();

    protected:

    private:
        int port;
};

#endif // SOCKETCLIENT_H
