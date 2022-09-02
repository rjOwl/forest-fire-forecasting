#ifndef PAYLOADRECEIVER_H
#define PAYLOADRECEIVER_H
#include <string>

// Abstract
class PayloadReceiver{
    public:
        void receiveSensorPayload();
        std::string getPayload();

    protected:

    private:
        std::string payload;
};

#endif // PAYLOADRECEIVER_H
