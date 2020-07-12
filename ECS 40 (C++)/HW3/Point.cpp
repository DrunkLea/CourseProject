// Shuyao Li
// 915277384

#include "Point.h"
#include<iostream>

  //int x, y;

Point Point::operator+(const Point& rhs) const {  return Point(rhs.x + x, rhs.y + y); }
Point Point::operator-(const Point& rhs) const {  return Point(rhs.x - x, rhs.y - y); }



std::ostream& operator<<(std::ostream& os, const Point& p) {
  os << "(" << p.x << "," << p.y << ")";
  return os;
}
std::istream& operator>>(std::istream& is, Point& p){
  is >> p.x >> p.y;
  return is;
}
