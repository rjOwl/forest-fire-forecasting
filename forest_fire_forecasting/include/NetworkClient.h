#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

/*
Description: The company has decided to invest into forest fire forecasting.
The first step is to gather data about the temperature from the sensory node located in the forest.

The node will be acting as server sending temperature grades (Celsius), each one second to a client.
The client shall calculate the following , as it gets the data:
·        Average over time.
·        Accumulation over time.

The client shall print the calculations each 5 seconds.

Languages: C++
Requirements:

1.     Utilize an automated build system.

2.     The code shall use VCS (version control system).

3.     The code shall include tests.

4.     A report shall be included in the repo indicating the design and implementation choices.

*/
class NetworkClient
{
    public:
        NetworkClient();

    protected:

    private:
        int temp=23;
};

#endif // NETWORKCLIENT_H
