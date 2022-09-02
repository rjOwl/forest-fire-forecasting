#include "TemperatureSensor.h"
#include "limits.h"
#include <cstdlib>

float TemperatureSensor::getTemperature(){
    return 1.8;
}

void TemperatureSensor::parseSetPayload(std::string rawPayload)
{
    TemperatureSensor::payload = rawPayload;
}

std::string TemperatureSensor::getParsedPayload(){
    return "ASD";
}


/*
TemperatureSensor::TemperatureSensor(){
    temperatureCounter = 0;
}
*/
/*
float TemperatureSensor::getTemperature(){
    return celsiusTemperature;
}

void TemperatureSensor::setTemperature(float newTemperaturReading){
    if (temperatureCounter == INT_MAX){
        celsiusTemperature = (newTemperaturReading + (celsiusTemperature)) /  2;
        temperatureCounter = 2;
    }else{
        celsiusTemperature = (newTemperaturReading + (temperatureCounter * celsiusTemperature)) / temperatureCounter + 1;
        temperatureCounter++;
    }
}

float TemperatureSensor::generateTemperature(int minReng, int maxReng){
    return minReng + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxReng-minReng)));
}
*/
