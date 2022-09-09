#include <iostream>
#include "SocketClient.h"
#include "TemperatureSensor.h"
#include "ILogger.h"
#include "LoggerFactory.h"
#include "TempOperations.h"

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

void printEachXSecond(int milliseconds, TempOperations *tempOp)
{
    string type = "console";
    LoggerFactory* loggerFactory = new LoggerFactory(type);
    ILogger* logger = loggerFactory->getLogger();

    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds)); // sleep for 1 second
        tempOp->setTempSum(tempOp->getCurrTemp());
        logger->log("Average: "+to_string(tempOp->calcAvgTemp()));
        logger->log("Accumulation: "+to_string(tempOp->calcAccumulatedTemp()));
        cout<<"============================="<<"\n";
    }
}

int main(){
    int connection_status=-1, sock=-1, port = 5001, addrlen, activity,
                              max_sd, sd, new_socket, connected_clients=0;

    int valread=0;
    char buffer[20] = { 0 };
    int milliseconds=5000;

    //PayloadReceiver payRec;
    SocketClient con(port);
    TempOperations tempOp;


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

    thread t1(printEachXSecond, milliseconds, &tempOp);
    cout<<"Waiting server reading...\n";
    /* listen on port */
    while(true){
        valread = read(con.sock, buffer, 20);
        if(valread == 0){
            cout<<"Server disconnected... :(\n";
            return -1;
        }
        tempOp.setCurrTemp(std::atof(buffer));
        tempOp.setTempCount();
        std::fill( std::begin( buffer ), std::end( buffer), 0 );
    }
    return 0;
}
