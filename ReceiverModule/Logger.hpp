#pragma once

#include <string>
using namespace std;

class Logger
{
    public:
        enum LogLevel { ERROR, WARNING, INFO};
    private:
        unsigned int log_level = WARNING;
    public:
        explicit Logger(int log_level);
        void info(const string& message);
        void warning(const string& message);
        void error(const string& message);
};