#ifndef LOGGERFACTORY_H
#define LOGGERFACTORY_H
#include "ILogger.h"

class LoggerFactory
{
    public:
        LoggerFactory(string);
        virtual ~LoggerFactory();
        ILogger* getLogger();


    protected:

    private:
        ILogger* logger;
};

#endif // LOGGERFACTORY_H
