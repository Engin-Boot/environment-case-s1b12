#include <iostream>
#include <future>
#include <chrono>
#include <string>
#include <ctime>
#include<vector>
#include "ReceiverModule/Logger.hpp"
#include "ReceiverModule/environment_checker.hpp"
#include"Lib/DataProcessingUtility.hpp"

#define RECEIVER_TIMEOUT 5
#define LOG_LEVEL_INFO 2
#define LOG_LEVEL_WARNING 1
#define LOG_LEVEL_ERROR 0

using namespace std;

void evaluate_data(string recv, Logger& log)
{
    DataProcessor d;
    vector<string> vec;
    vector<string> vec2;
    vec = d.split(recv);
    for(auto data : vec)
    {
        vec2.push_back(DataProcessor::trim(data));
    }
    vector<double> vec1;
    d.populateDoubleVector(vec1,vec2,2);
    check_environment(vec1, log);
}

bool AsyncGetline(std::string& recv)
{
    bool isDataReceived = getline(cin, recv).good();
    return isDataReceived;
}

void process(const std::string& recv, const std::string& timestamp, Logger& log)
{
    if (recv == "q")
        std::cout << "QUIT: USER INTERRUPT" << std::endl;
    else
    {
        std::cout << timestamp << " ";
        log.info(recv);
        evaluate_data(recv, log);
    }
}

void processIfDataReceived(bool isDataReceived, const std::string& recv, const std::string& timestamp, Logger& log)
{
    if(isDataReceived)
    {
        process(recv, timestamp, log);
    }
}

bool timeout(future<bool>& fu)
{
    return fu.wait_until(std::chrono::steady_clock::now() + std::chrono::seconds(RECEIVER_TIMEOUT)) == std::future_status::timeout;
}


int main()
{
    std::string recv = "";
    bool isDataReceived = true;
    Logger log(LOG_LEVEL_INFO);
    
    while (recv != "q" && isDataReceived)
    {

        future<bool> fu = std::async(AsyncGetline, std::ref(recv));

        if(timeout(fu))
        {
            log.warning("No Data Received"); 
            exit(0);
        }

        isDataReceived = fu.get();

        auto end_time = std::chrono::system_clock::now();
        std::time_t timestamp = std::chrono::system_clock::to_time_t(end_time);
        std::string s_timestamp = std::ctime(&timestamp);

        processIfDataReceived(isDataReceived, recv, s_timestamp, log);
    }
    return 0;
}