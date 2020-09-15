#include "../Lib/catch/catch.hpp"
#include "Timer.hpp"
#include <chrono>

TEST_CASE()
{
    int expected_sleep_time_sec = 2;
    Timer timer;
    auto start = std::chrono::high_resolution_clock::now();
    timer.sleep_for(2);
    auto end = std::chrono::high_resolution_clock::now();
    auto actual_sleep_time_ns = end - start;
    int actual_sleep_time_sec = actual_sleep_time_ns.count()/1000000000; 
    REQUIRE(expected_sleep_time_sec == actual_sleep_time_sec);
}