#ifndef PAYLOADPARSER_H
#define PAYLOADPARSER_H
#include <string>

// Abstract
class PayloadParser{
    public:
        // each sensor sends data differently so each parser will have different implementation
        virtual void parseSetPayload(std::string rawPayload)=0;
        //This should be generic class type
        virtual std::string getParsedPayload()=0;
    protected:
    private:
        std::string payload;
};

#endif // PAYLOADPARSER_H
