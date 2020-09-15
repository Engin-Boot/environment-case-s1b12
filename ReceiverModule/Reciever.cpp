#include <iostream>
#include <iostream>
#include <future>
#include <chrono>
#include <string>
#include <thread>
#include <ctime>
#include "DataProcessingUtility.hpp"
#include<sstream>
using namespace std;

string res;
bool set = true;
bool myAsyncGetline()
{
    set = getline(cin, res).good();
    return true;
}

void process(const std::string &timestamp)
{
    vector<double> vec3;
    vector<string> vec1,vec2;
    string r = res;
    if (res == "q")
        std::cout << "QUIT: USER INTERRUPT" << std::endl;
    else
    {
        std::cout << timestamp << " "
                  << "INFO: " << res << std::endl;
        vec1=split(r);
        for(auto i:vec1)
        {
            vec2.push_back(trim(i));
        }
        populateDoubleVector(vec3,vec2,2);
    }
    cout<<vec3[0]<<vec3[1]<<endl;
}


int main()
{
    while (res != "q" && set)
    {
        auto start = std::chrono::system_clock::now();
        future<bool> fu = std::async(myAsyncGetline);
        if (fu.wait_until(std::chrono::steady_clock::now() + std::chrono::seconds(10)) == std::future_status::timeout)
        {
            auto end = std::chrono::system_clock::now();
            std::time_t end_time = std::chrono::system_clock::to_time_t(end);
            std::cout << std::ctime(&end_time) << " "
                      << "Too Late!\n"; // 1
            exit(0);
        }
        else
        {
            auto end = std::chrono::system_clock::now();
            std::time_t end_time = std::chrono::system_clock::to_time_t(end);
            if (set)
                process(std::ctime(&end_time));
        }
    }
    return 0;
}