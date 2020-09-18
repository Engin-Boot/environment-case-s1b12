#include "Alerter.hpp"

class Alerter
{
public:
  std::string raiseAlert(const std::string& level, const std::string &name, const std::string& message)
  {
    std::string alert_message = "[" + level + "] " + name + ": " + message;
    return alert_message;
  }

  std::string AlertFatalError(const std::string& message)
  {
    std::string alert_message = "[FATAL]: " + message;
    return alert_message;
  }
};