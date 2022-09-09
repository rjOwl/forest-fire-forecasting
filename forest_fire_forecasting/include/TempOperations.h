#ifndef TEMPOPERATIONS_H
#define TEMPOPERATIONS_H
#include "TemperatureSensor.h"

class TempOperations : public TemperatureSensor
{
    public:
        TempOperations();
        virtual ~TempOperations();
        float getTempSum();
        void setTempSum(float );

        int getTempCount();
        void setTempCount();

        float calcAvgTemp();
        float calcAccumulatedTemp();

    protected:

    private:
        float temp_sum=0;
        int temp_count=0;
};

#endif // TEMPOPERATIONS_H
