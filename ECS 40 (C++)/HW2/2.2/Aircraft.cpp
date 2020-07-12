//Shuyao Li
// 915277384

#include "Aircraft.h"
#include<iostream>
#include<string>


Aircraft::Aircraft(int n, std::string name_str): numEng(n), nm(name_str)
{ hrs = new int[n];}
const std::string Aircraft::name(void) const { return nm; }
int Aircraft::numEngines(void) const { return numEng;  }
void Aircraft::setHours(int i, int h) { hrs[i-1] = h;}
void Aircraft::print(void) const
{
  std::cout << "Aircraft: " << nm << " type: "
  << type() << " has " << numEng << " engines" << std::endl;

  for (int i = 0; i < numEng; i++) {
    std::cout << "engine " << i + 1 << ": " << hrs[i] << " hours" << std::endl;
  }
}
void Aircraft::printSchedule(void) const
{
  std::cout << "Maintenance schedule for " << nm << std::endl;
  for (int i = 0; i < numEng; i++) {
    int remainTime = maxHours() - hrs[i];
    if (remainTime <= 0)
      std::cout << "engine " << i + 1 << ": maintenance due now!!" << std::endl;
    else
      std::cout << "engine " << i + 1 << ": maintenance due in " << remainTime << " hours" << std::endl;
  }
}
Aircraft* Aircraft::makeAircraft(char ch, std::string name_str)
{
  if (ch == 'A')
    return new A380(name_str);
  else if (ch == 'B')
    return new B737(name_str);
  else{
    return 0;
  }
}
Aircraft::~Aircraft(void){}


A380::A380(std::string name_str): Aircraft(4, name_str) {}
const std::string A380::type(void) const
{ return "Airbus A380";  }
const int A380::maxHours(void) const
{ return 750; }

B737::B737(std::string name_str) :Aircraft(2, name_str){}
const std::string B737::type(void) const
{ return "Boeing 737";  }

const int B737::maxHours(void) const
{ return 500; }
