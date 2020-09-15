#include "Timer.hpp"
#include <iostream>
#include <thread>

Timer::Timer()
{
    std::chrono::high_resolution_clock::now();
}

void Timer::sleep_for(int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

Timer::~Timer()
{
    std::chrono::high_resolution_clock::now();
}