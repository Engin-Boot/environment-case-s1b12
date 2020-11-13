#pragma once 

#include <vector>
#include "Logger.hpp"
using namespace std;

extern void checkwhetherhigtemp(double temp, Logger& log);
extern void checkwhetherveryhightemp(double temp, Logger& log);
extern void checkwhetherlowtemp(double temp, Logger& log);
extern void checkwhetherverylowtemp(double temp, Logger& log);
extern void checkwhetherhighhumidity(double hum, Logger& log);
extern void checkwhetherveryhighhumidity(double hum, Logger& log);
extern void check_environment(vector<double> & v, Logger& log);