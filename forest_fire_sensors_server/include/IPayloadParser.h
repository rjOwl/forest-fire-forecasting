#ifndef IPAYLOADPARSER_H
#define IPAYLOADPARSER_H
#include <string>
#include "PayloadReceiver.h"
using namespace std;

// Abstract
class IPayloadParser{
    public:
        // each sensor sends data differently so each parser will have different implementation
        virtual void parsePayload(string)=0;
        //This should be generic class type
        virtual string getParsedPayload()=0;
    protected:
//    string rawPayload;
    private:
};

#endif // PAYLOADPARSER_H
