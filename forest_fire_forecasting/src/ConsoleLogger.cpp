#include "ConsoleLogger.h"
#include <iostream>
ConsoleLogger::ConsoleLogger()
{
    //ctor
}

ConsoleLogger::~ConsoleLogger()
{
    //dtor
}


void ConsoleLogger::log(string data){
    cout<<data<<"\n";
}
