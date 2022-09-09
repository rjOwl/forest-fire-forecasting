#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H
#include "ILogger.h"

class ConsoleLogger: public ILogger
{
    public:
        ConsoleLogger();
        virtual ~ConsoleLogger();
        void log(string);

    protected:

    private:
};

#endif // CONSOLELOGGER_H
