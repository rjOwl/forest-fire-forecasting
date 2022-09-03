#include <iostream>
#include "TemperatureSensor.h"
#include "PayloadReceiver.h"

using namespace std;

int main()
{

    TemperatureSensor temperatureSensor;
    PayloadReceiver payRec = PayloadReceiver();
    payRec.receiveSensorPayload();

    std::cout << temperatureSensor.getParsedPayload() << std::endl;
    std::cout << payRec.getPayload() << std::endl;
    return 0;
}

    /**
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

