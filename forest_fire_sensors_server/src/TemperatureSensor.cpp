#include "TemperatureSensor.h"
#include "limits.h"
#include <cstdlib>


string TemperatureSensor::getParsedPayload(){}


void TemperatureSensor::parsePayload(string rawPayload) {
    size_t pos_start = 0, pos_end, delim_len = TemperatureSensor::delimiter.length();
    string token;

    while ((pos_end = rawPayload.find (TemperatureSensor::delimiter, pos_start)) != string::npos) {
        token = rawPayload.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        TemperatureSensor::parsedPayload.push_back(token);
    }
    TemperatureSensor::parsedPayload.push_back (rawPayload.substr (pos_start));
    TemperatureSensor::timestamp = TemperatureSensor::parsedPayload[1];
    TemperatureSensor::temp = TemperatureSensor::parsedPayload[2];
}

string TemperatureSensor::getTemp(){
    return TemperatureSensor::temp;
}

string TemperatureSensor::getTimestamp(){
    return TemperatureSensor::timestamp;
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
