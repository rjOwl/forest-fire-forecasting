#ifndef PAYLOADPARSER_H
#define PAYLOADPARSER_H


class PayloadParser
{
    public:
        PayloadParser();
        virtual void receivePayload() = 0;

    protected:

    private:
};

#endif // PAYLOADPARSER_H
