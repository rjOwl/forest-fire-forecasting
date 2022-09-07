#include "TempOperations.h"

TempOperations::TempOperations()
{
    //ctor
}

TempOperations::~TempOperations()
{
    //dtor
}


void TempOperations::setTempSum(float temp){
    TempOperations::temp_sum+=temp;
}

float TempOperations::getTempSum(){
    return TempOperations::temp_sum;
}

float TempOperations::calcAvgTemp(){
    return TempOperations::temp_sum / TempOperations::temp_count;
}
float TempOperations::calcAccumulatedTemp(){
    return TempOperations::temp_count;
}

void TempOperations::setTempCount(){
    TempOperations::temp_count+=1;
}
int TempOperations::getTempCount(){
    return TempOperations::temp_count;
}

