#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include <string>
#include <PayloadParser.h>


class TemperatureSensor : public PayloadParser{

    public:
        float getTemperature();
        virtual void parseSetPayload(std::string rawPayload);
        //This should be generic class type
        virtual std::string getParsedPayload();

        /*
        void setTemperature(float newTemperaturReading);
        float generateTemperature(int minReng, int maxReng);
        */
    protected:

    private:
        std::string payload;
        float celsius_temp;
        std::string timestamp;
};

#endif // TEMPERATURESENSOR_H
