// Shuyao Li
// 915288384

#include "Runway.h"
#include<iostream>
#include<iterator>
#include<sstream>

//public:
  Runway::Runway(std::string s)
    :site_number_(s.substr(0,10)),name_(s.substr(13,7)),length_(convert_length(s.substr(21,4))){  }
  std::string Runway::site_number(void) const{return site_number_;}
  std::string Runway::name(void) const {return name_;}
  int Runway::length(void) const {return length_;}
//private:
  int Runway::convert_length(std::string s) const{
    std::istringstream is(s);
    int len;
    is >> len;
    return len;
  }
