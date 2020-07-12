// Shuyao Li
// 915288384

#ifndef CODE_H
#define CODE_H
#include "Facility.h"
#include <string>

class Code{
public:
  Code(std::string s): code_(s) {}
  bool operator() (Facility *f) { return !code_.compare(f->code());}
private:
  const std::string code_;
};

#endif
