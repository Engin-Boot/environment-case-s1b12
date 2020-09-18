#pragma once 
#include <string>

class Alerter
{
public:
  std::string raiseAlert(const std::string& level, const std::string &name, const std::string& message);
  std::string AlertFatalError(const std::string& message);
};