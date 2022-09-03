#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H


class NetworkClient
{
    public:
        NetworkClient();
        virtual void establishCon()=0;
        virtual void recieveSensorData()=0;
        virtual void sendData()=0;

    protected:

    private:
};

#endif // NETWORKCLIENT_H
