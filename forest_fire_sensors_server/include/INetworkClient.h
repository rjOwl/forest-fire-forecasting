#ifndef INETWORKCLIENT_H
#define INETWORKCLIENT_H

class INetworkClient{
    public:
        virtual int establishCon()=0;
        virtual void recieveSensorData()=0;
        virtual void sendData()=0;

    protected:

    private:
};

#endif // NETWORKCLIENT_H
