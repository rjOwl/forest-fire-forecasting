#include "PayloadReceiver.h"

void PayloadReceiver::receiveSensorPayload(string rawPayload)
{
    PayloadReceiver::rawPayload = rawPayload;//"27, 9/2/2022, 26.8";
}

string PayloadReceiver::getPayload()
{
    return PayloadReceiver::rawPayload;
}
