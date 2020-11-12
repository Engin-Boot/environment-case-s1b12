#include <iostream>
#include <future>
#include <chrono>
#include <string>
#include <ctime>
#include<vector>
#include"Lib/DataProcessingUtility.hpp"

#define RECEIVER_TIMEOUT 5
using namespace std;

void checkwhetherhigtemp(double temp)
{
    if(temp>=37 && temp<=40)
    {
        cout<<"Warning High Temperature!!"<<endl;
    }
}
void checkwhetherveryhightemp(double temp)
{
    if(temp>40)
    {
        cout<<"Error High temperature"<<endl;
    }
}

void checkwhetherlowtemp(double temp)
{
    if(temp<=4&& temp >=0)
    {
        cout<<"Warning Low Temperature"<<endl;
    }

}
void checkwhetherverylowtemp(double temp)
{
    if(temp<0)
    {
        cout<<"Error Low Temperature"<<endl;
    }
}
void checkwhetherhighhumidity(double hum)
{
    if (hum>=70 && hum<=90)
    {
        cout<<"Warning High Humidity"<<endl;
    }
}
void checkwhetherveryhighhumidity(double hum)
{
    if(hum>90)
    {
        cout<<"Error High Humidity"<<endl;
    }
}

void check_environment(vector<double> & v)
{
    checkwhetherhigtemp(v[0]);
    checkwhetherlowtemp(v[0]);
    checkwhetherveryhightemp(v[0]);
    checkwhetherverylowtemp(v[0]);
    checkwhetherhighhumidity(v[1]);
    checkwhetherveryhighhumidity(v[1]);
}
void evaluate_data(string recv)
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
    check_environment(vec1);
}

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
    {
        std::cout << timestamp << "INFO: " << recv << std::endl;
        evaluate_data(recv);
    }
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