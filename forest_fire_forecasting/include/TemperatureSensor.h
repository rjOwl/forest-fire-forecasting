#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H


class TemperatureSensor
{
    public:
        TemperatureSensor();
        virtual ~TemperatureSensor();
        void setCurrTemp(float currTemp);
        float getCurrTemp();
    protected:
    private:
        float current_temp=0;
};

#endif // TEMPERATURESENSOR_H
