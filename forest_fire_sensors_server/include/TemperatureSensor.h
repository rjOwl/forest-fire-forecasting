#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "IPayloadParser.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;
class TemperatureSensor : public IPayloadParser{

    public:
        // each sensor sends data differently so each parser will have different implementation
        void parsePayload(string);
        //This should be generic class type
        string getTemp();
        string getTimestamp();

        //This should be generic class type
        string getParsedPayload();

        /*
        void setTemperature(float newTemperaturReading);
        float generateTemperature(int minReng, int maxReng);
        */
    protected:

    private:
        vector<string> parsedPayload;
        string temp, timestamp, delimiter=",";
        float celsius_temp;
};

#endif // TEMPERATURESENSOR_H
