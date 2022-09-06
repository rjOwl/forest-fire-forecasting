#ifndef CONSOLLOGGER_H
#define CONSOLLOGGER_H
#include <string>
#include "ILogger.h"
using namespace std;

class ConsolLogger : public ILogger{
    public:
        ConsolLogger();
        virtual ~ConsolLogger();
        void logData(string);
    protected:

    private:
};

#endif // CONSOLLOGGER_H
