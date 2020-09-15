#include<iostream>
#include<string>
using namespace std;
class Alerter
{
    public:
    void raiseAlert(const char* level,string& name ,const char* message )
    {
        cout<<"["<<level<<"] "<<name<<" is "<<message<<endl;
    }
};
class RangeChecker
{
  private:
    Alerter* alert;
    int lower;
    int upper;
    int maxlimit;
    int minlimit;
    string name; 
  public:
    RangeChecker(string pname,int up,int mxlimit,int low=0,int mnlimit=0)
    {
      name=pname;
      lower = low;
      upper = up;
      maxlimit=mxlimit;
      minlimit=mnlimit;
    }
    void checkwhetherlowpara(float value)
    {
        if(value <= lower && value>=minlimit ) 
      {
        //cout<<"Warning Low "<<name<<"!"<<endl;
        alert->raiseAlert("Warning",name,"Low");
      }
    }
    void checkwhetherhighpara(float value)
    {
        if(value >= upper && value <=maxlimit) 
      {
        alert->raiseAlert("Warning",name,"High");
      }
    }
    void checkwhetherveryhighpara(float value)
    {
        if(value>maxlimit)
      {
        alert->raiseAlert("Error",name,"Very High");
      }
    }
    void checkwhetherverylowpara(float value)
    {
    if(value<minlimit)
      {
        alert->raiseAlert("Error",name," Very Low");
      }
    }
    void checkAgainstRange(float value)
    {
      checkwhetherhighpara(value);
      checkwhetherlowpara(value);
      checkwhetherveryhighpara(value);
      checkwhetherverylowpara(value);
    }
};

class EnvironmentChecker
{
  private:
    int hightemp,veryhightemp,lowtemp,verylowtemp;
    int highhum,veryhighhum;
    RangeChecker tem,hum;
  public:
    EnvironmentChecker(int high,int veryhigh,int low,int verylow,int highhum,int veryhighum):
      hightemp(high),
      veryhightemp(veryhigh),
      lowtemp(low),
      verylowtemp(verylow),
      highhum(highhum),
      veryhighhum(veryhighum),
    tem("Temperature",hightemp,veryhightemp,lowtemp,verylowtemp),
      hum("Humidity",highhum,veryhighhum)
      
    {}
    void checkAllParameters(float temp, float humidity)
    {
      tem.checkAgainstRange(temp);
      hum.checkAgainstRange(humidity);
    }
};

int main() {
  EnvironmentChecker parameters(37,40,4,0,70,90);
  parameters.checkAllParameters(34, 66);
  parameters.checkAllParameters(40, 78);
  parameters.checkAllParameters(-1, 92);
  parameters.checkAllParameters(2, 45);
}