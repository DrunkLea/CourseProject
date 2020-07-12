// Shuyao Li
// 915288384

#ifndef SITENUMBER_H
#define SITENUMBER_H
#include "Facility.h"
#include "Runway.h"
#include <string>

template< typename T>
class SiteNumber{
public:
  SiteNumber(std::string s): site_number_(s) {}

  bool operator() (T *t) { return !site_number_.compare(t->site_number());}
private:
  const std::string site_number_;
};
#endif
