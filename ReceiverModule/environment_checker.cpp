#include <iostream>
#include <vector>
#include <string>
#include "Logger.hpp"

#define HIGH_TEMPERATURE_LOWER_LIMIT 37
#define HIGH_TEMPERATURE_UPPER_LIMIT 40
#define LOW_TEMPERATURE_LOWER_LIMIT 0
#define LOW_TEMPERATURE_UPPER_LIMIT 4
#define HIGH_HUMIDITY_THRESHOLD 70
#define VERY_HIGH_HUMIDITY_THRESHOLD 90 

using namespace std;

void checkwhetherhigtemp(Logger& log, double temp)
{
    if(temp >= HIGH_TEMPERATURE_LOWER_LIMIT && temp <= HIGH_TEMPERATURE_UPPER_LIMIT)
    {
        log.warning("High Temperature!!");
    }
}

void checkwhetherveryhightemp(Logger& log, double temp)
{
    if(temp > HIGH_TEMPERATURE_UPPER_LIMIT)
    {
        log.error("High Temperature");
    }
}

void checkwhetherlowtemp(Logger& log, double temp)
{
    if(temp <= LOW_TEMPERATURE_UPPER_LIMIT && temp >= LOW_TEMPERATURE_LOWER_LIMIT)
    {
        log.warning("Low Temperature");
    }
}

void checkwhetherverylowtemp(Logger& log, double temp)
{
    if(temp < LOW_TEMPERATURE_LOWER_LIMIT)
    {
        log.error("Low Temperature");
    }
}

void checkwhetherhighhumidity(Logger& log, double hum)
{
    if (hum >= HIGH_HUMIDITY_THRESHOLD && hum <= VERY_HIGH_HUMIDITY_THRESHOLD)
    {
        log.warning("High Humidity");
    }
}

void checkwhetherveryhighhumidity(Logger& log, double hum)
{
    if(hum > VERY_HIGH_HUMIDITY_THRESHOLD)
    {
        log.error("Very High Humidity");
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
