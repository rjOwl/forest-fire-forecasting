#ifndef LOGGERFACTORY_H
#define LOGGERFACTORY_H
#include "ILogger.h"

class LoggerFactory
{
    public:
        LoggerFactory();
        virtual ~LoggerFactory();
//        ILogger getLogger(string);

    protected:

    private:
    string env;
};

#endif // LOGGERFACTORY_H
