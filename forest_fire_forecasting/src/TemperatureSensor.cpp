#include "TemperatureSensor.h"
#include <iostream>
using namespace std;
TemperatureSensor::TemperatureSensor()
{
    //ctor
}

TemperatureSensor::~TemperatureSensor()
{
    //dtor
}

void TemperatureSensor::setCurrTemp(float currTemp){
    TemperatureSensor::current_temp = currTemp;
}

float TemperatureSensor::getCurrTemp(){
    return TemperatureSensor::current_temp;
}
