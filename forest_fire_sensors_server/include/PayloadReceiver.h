#ifndef PAYLOADRECEIVER_H
#define PAYLOADRECEIVER_H
#include <string>
using namespace std;

class PayloadReceiver{
    public:
        void receiveSensorPayload(string);
        string getPayload();
    protected:

    private:
        string rawPayload;
};

#endif // PAYLOADRECEIVER_H
