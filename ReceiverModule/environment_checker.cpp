#include <iostream>
#include <vector>
#include <string>
#include "Logger.hpp"
using namespace std;

void checkwhetherhigtemp(Logger& log, double temp)
{
    if(temp>=37 && temp<=40)
    {
        log.warning("High Temperature!!");
    }
}

void checkwhetherveryhightemp(Logger& log, double temp)
{
    if(temp>40)
    {
        log.error("High Temperature");
    }
}

void checkwhetherlowtemp(Logger& log, double temp)
{
    if(temp<=4&& temp >=0)
    {
        log.warning("Low Temperature");
    }
}

void checkwhetherverylowtemp(Logger& log, double temp)
{
    if(temp<0)
    {
        log.error("Low Temperature");
    }
}

void checkwhetherhighhumidity(Logger& log, double hum)
{
    if (hum>=70 && hum<=90)
    {
        log.warning("High Humidity");
    }
}

void checkwhetherveryhighhumidity(Logger& log, double hum)
{
    if(hum>90)
    {
        log.error("High Humidity");
    }
}

void check_environment(vector<double> & v, Logger& log)
{
    checkwhetherhigtemp(log, v[0]);
    checkwhetherlowtemp(log, v[0]);
    checkwhetherveryhightemp(log, v[0]);
    checkwhetherverylowtemp(log, v[0]);
    checkwhetherhighhumidity(log, v[1]);
    checkwhetherveryhighhumidity(log, v[1]);
}
