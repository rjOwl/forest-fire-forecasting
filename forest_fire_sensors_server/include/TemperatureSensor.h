#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include <string>
#include <PayloadParser.h>

class TemperatureSensor : public PayloadParser{

    public:
        float getTemperature();

        /*
        void setTemperature(float newTemperaturReading);
        float generateTemperature(int minReng, int maxReng);
        */
    protected:

    private:
        float celsius_temp;
        std::string timestamp;
};

#endif // TEMPERATURESENSOR_H
