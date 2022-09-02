#include <iostream>
#include "TemperatureSensor.h"
#include "PayloadReceiver.h"

using namespace std;

int main()
{
    TemperatureSensor temperatureSensor;
    PayloadReceiver payRec = PayloadReceiver();
    payRec.receiveSensorPayload();

//    std::cout << temperatureSensor.generateTemperature(10,20) << std::endl;
    std::cout << payRec.getPayload() << std::endl;
    return 0;
}
