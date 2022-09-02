#include "PayloadReceiver.h"

void PayloadReceiver::receiveSensorPayload()
{
    PayloadReceiver::payload = "27, 9/2/2022, 26.8";
}

std::string PayloadReceiver::getPayload()
{
    return PayloadReceiver::payload;
}
