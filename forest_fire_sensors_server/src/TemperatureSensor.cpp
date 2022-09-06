#include "TemperatureSensor.h"
#include "limits.h"
#include <cstdlib>

#include <iostream>

string TemperatureSensor::getParsedPayload(){}


void TemperatureSensor::parsePayload(string rawPayload) {
    size_t pos_start = 0, pos_end, delim_len = TemperatureSensor::delimiter.length();
    vector<string> parsedPayload;
    string token;

    while ((pos_end = rawPayload.find (TemperatureSensor::delimiter, pos_start)) != string::npos) {
        token = rawPayload.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        parsedPayload.push_back(token);
    }
    parsedPayload.push_back (rawPayload.substr (pos_start));
    TemperatureSensor::timestamp = parsedPayload[1];
    TemperatureSensor::temp = parsedPayload[2];
}

string TemperatureSensor::getTemp(){
    return TemperatureSensor::temp;
}

string TemperatureSensor::getTimestamp(){
    return TemperatureSensor::timestamp;
}

