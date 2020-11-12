#include <iostream>
#include <string>
#include <vector>
#include "Alerter.hpp"

using namespace std;
class RangeChecker
{
private:
  Alerter *alert;
  int lower;
  int upper;
  int maxlimit;
  int minlimit;
  string name;

public:
  RangeChecker(const string& pname, int up, int mxlimit, int low = 0, int mnlimit = 0)
  {
    name = pname;
    lower = low;
    upper = up;
    maxlimit = mxlimit;
    minlimit = mnlimit;
  }
  std::string checkwhetherlowpara(double value)
  {
    std::string log_message = "";
    if (value <= lower && value >= minlimit)
    {
      log_message = alert->raiseAlert("Warning", name, "Low");
    }
    return log_message;
  }
  std::string checkwhetherhighpara(double value)
  {
    std::string log_message = "";
    if (value >= upper && value <= maxlimit)
    {
      log_message = alert->raiseAlert("Warning", name, "High");
    }
    return log_message;
  }
  std::string checkwhetherveryhighpara(double value)
  {
    std::string log_message = "";
    if (value > maxlimit)
    {
      log_message = alert->raiseAlert("Error", name, "Too High");
    }
    return log_message;
  }
  std::string checkwhetherverylowpara(double value)
  {
    std::string log_message = "";
    if (value < minlimit)
    {
      log_message = alert->raiseAlert("Error", name, " Too Low");
    }
    return log_message;
  }
  std::vector<std::string> checkAgainstRange(double value)
  {
    std::vector<std::string> Logs;
    Logs.push_back(checkwhetherhighpara(value));
    Logs.push_back(checkwhetherlowpara(value));
    Logs.push_back(checkwhetherveryhighpara(value));
    Logs.push_back(checkwhetherverylowpara(value));
    return Logs;
  }
};

class EnvironmentChecker
{
private:
  int hightemp, veryhightemp, lowtemp, verylowtemp;
  int highhum, veryhighhum;
  RangeChecker tem, hum;

public:
  EnvironmentChecker(int high, int veryhigh, int low, int verylow, int highhum, int veryhighum) : hightemp(high),
                                                                                                  veryhightemp(veryhigh),
                                                                                                  lowtemp(low),
                                                                                                  verylowtemp(verylow),
                                                                                                  highhum(highhum),
                                                                                                  veryhighhum(veryhighum),
                                                                                                  tem("Temperature", hightemp, veryhightemp, lowtemp, verylowtemp),
                                                                                                  hum("Humidity", highhum, veryhighhum)

  {
  }
  std::vector<std::string> checkAllParameters(double temp, double humidity)
  {
    tem.checkAgainstRange(temp);
    hum.checkAgainstRange(humidity);
  }
};