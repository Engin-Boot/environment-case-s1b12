#include <iostream>
#include <future>
#include <chrono>
#include <string>
#include <ctime>
#define RECEIVER_TIMEOUT 5
using namespace std;

bool AsyncGetline(std::string& recv)
{
    bool isDataReceived = getline(cin, recv).good();
    return isDataReceived;
}

void process(const std::string& recv, const std::string& timestamp)
{
    if (recv == "q")
        std::cout << "QUIT: USER INTERRUPT" << std::endl;
    else
        std::cout << timestamp << "INFO: " << recv << std::endl;
}

void processIfDataReceived(bool isDataReceived, const std::string& recv, const std::string& timestamp)
{
    if(isDataReceived)
    {
        process(recv, timestamp);
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
    
    while (recv != "q" && isDataReceived)
    {

        future<bool> fu = std::async(AsyncGetline, std::ref(recv));

        if(timeout(fu))
        {
            std::cout << "[FATAL] No Data received\n"; 
            exit(0);
        }

        isDataReceived = fu.get();

        auto end_time = std::chrono::system_clock::now();
        std::time_t timestamp = std::chrono::system_clock::to_time_t(end_time);
        std::string s_timestamp = std::ctime(&timestamp);

        processIfDataReceived(isDataReceived, recv, s_timestamp);
    }
    return 0;
}