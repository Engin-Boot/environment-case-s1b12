#pragma once
#include <chrono>

class Timer
{
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    public:
        Timer();
        void sleep_for(int seconds);
        ~Timer();
};