#include <iostream>
#include "Logger.hpp"

Logger::Logger(int log_level):log_level(log_level) {}

void Logger::info(const string& message)
{
    if(log_level >= INFO)
        cout << "[INFO] : " << message << endl;
}

void Logger::warning(const string& message)
{
    if(log_level >= WARNING)
        cout << "[WARNING] : " << message << endl;
}

void Logger::error(const string& message)
{
    if(log_level >= ERROR)
        cout << "[ERROR] : " << message << endl;
}
