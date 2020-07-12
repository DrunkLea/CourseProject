// Shuyao Li
// 915277384

#include "Shape.h"
#include <iostream>

Rectangle::~Rectangle(void){}
bool Rectangle::overlaps(const Shape& r) const{
  return r.overlaps(*this);
}
bool Rectangle::overlaps(const Circle& r) const{
  Point nearest;
  nearest.x = std::min(std::max(r.center.x, position.x), position.x + width);
  nearest.y = std::min(std::max(r.center.y, position.y), position.y + height);
  if ((nearest.x-r.center.x)*(nearest.x-r.center.x) +
    (nearest.y-r.center.y)*(nearest.y-r.center.y) < r.radius*r.radius)
    return true;
  return false;
}
bool Rectangle::overlaps(const Rectangle& r) const{
  if (r.position.x + r.width <= position.x
    || r.position.x >= position.x + width
    || r.position.y >= position.y + height
    || r.position.y + r.height <= position.y)
    return false;
  return true;
}
bool Rectangle::fits_in(const Rectangle& r) const{
  if (position.x + width <= r.width && position.y + height <= r.height)
    return true;
  return false;
}
void Rectangle::draw(void) const
{
  std::cout<<"<rect x=\""<<position.x<<"\" y=\""<<position.y<<
  "\" width=\""<<width<<"\" height=\""<<height<<"\"/>"<<std::endl;
}

Circle::~Circle(void){}
bool Circle::overlaps(const Shape& s) const{
  return s.overlaps(*this);
}
bool Circle::overlaps(const Circle& r) const{
  if (((r.center.x-center.x)*(r.center.x-center.x))
  + ((r.center.y-center.y)*(r.center.y-center.y)) < r.radius*r.radius + radius*radius)
    return true;
  return false;
}
bool Circle::overlaps(const Rectangle& r) const{
  return r.overlaps(*this);
}
bool Circle::fits_in(const Rectangle& r) const{
  if(center.x + radius <= r.width && center.y + radius <= r.height)
    return true;
  return false;
}
void Circle::draw(void) const
{
  std::cout<<"<circle cx=\""<<center.x<<"\" cy=\""<<center.y<<"\" r=\""<<radius<<"\"/>"<<std::endl;
}
