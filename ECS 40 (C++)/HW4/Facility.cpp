// Shuyao Li
// 915288384

#include "Facility.h"
#include "gcdistance.h"
#include<iostream>
#include<iterator>
#include<sstream>


Facility::Facility(std::string s)
  :site_number_(s.substr(0,10))
  ,type_(s.substr(11,13))
  ,code_(s.substr(24,4))
  ,name_(s.substr(130,50))
  ,latitude_(convert_latitude(s.substr(535,12)))
  ,longitude_(convert_longitude(s.substr(562,12)))
  {}

std::string Facility::site_number(void) const {return site_number_;}
std::string Facility::type(void) const {return type_;}
std::string Facility::code(void) const{return code_;}
std::string Facility::name(void) const {return name_;}
double Facility::latitude(void) const {return latitude_;}
double Facility::longitude(void) const{return longitude_;}
double Facility::distance(double lat, double lon) const {return gcdistance(lat,lon,latitude_,longitude_);}

//private:
double Facility::convert_latitude(std::string s) const{
  //std::cout<<"# in lat: "<<s.substr(0,11)<<" char in lat: "<< s.substr(11,1)<<std::endl;
  std::istringstream is1(s.substr(0,11)),is2(s.substr(11,1));
  double lat;
  is1 >> lat;
  char dir;
  is2 >> dir;
  if (dir == 'S')
    lat *= -1;

  return lat/3600;
}
double Facility::convert_longitude(std::string s) const{
  std::istringstream is1(s.substr(0,11)),is2(s.substr(11,1));
  double lon;
  is1 >> lon;

  char dir;
  is2 >> dir;
  if (dir == 'W')
    lon *= -1;

  return lon/3600;
}
