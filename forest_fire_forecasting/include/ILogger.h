#ifndef ILOGGER_H
#define ILOGGER_H
#include <string>

using namespace std;

class ILogger
{
    public:
        virtual void log(string)=0;
    protected:

    private:
};

#endif // ILOGGER_H
