#include "LoggerFactory.h"
#include "ConsoleLogger.h"

LoggerFactory::LoggerFactory(string type)
{
    if(type=="console")
        LoggerFactory::logger = new ConsoleLogger();
    else
        LoggerFactory::logger  = nullptr;
}

LoggerFactory::~LoggerFactory()
{
    //dtor
}

ILogger* LoggerFactory::getLogger(){
    return LoggerFactory::logger;
}

static ILogger* createLogger(string type){
    if(type == "console")
        return new ConsoleLogger();
}
