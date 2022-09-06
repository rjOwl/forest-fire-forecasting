#ifndef ILOGGER_H
#define ILOGGER_H
#include <string>
using namespace std;

class ILogger
{
    public:
        virtual void logData()=0;

    protected:

    private:
        string env;
};

#endif // ILOGGER_H
