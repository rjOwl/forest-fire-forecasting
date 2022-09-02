#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H


class NetworkClient
{
    public:
        NetworkClient();
        void establishCon();
        void recieveSensorData();
        void sendData();

    protected:

    private:
};

#endif // NETWORKCLIENT_H
