// Shuyao Li
// 915277384
// Fraction.cpp

#include "Fraction.h"
#include<iostream>
#include<stdexcept>
using std::cin;
using std::cout;
using std::endl;

   Fraction::Fraction(void){}
   Fraction::Fraction(int a, int b)
    {
      if ( den == 0 )
        throw std::invalid_argument("must be positive");
      num = a;
      den = b;
      reduce_fraction();
    }
  Fraction::~Fraction(void) {}

  int Fraction::getNum(void) const
  { return num; }
  int Fraction::getDen(void) const
  { return den; }

  Fraction Fraction::operator=(const Fraction& rhs)
  {
    if ( &rhs == this )
      return *this;
    this->num = rhs.num;
    this->den = rhs.den;

    return *this;
  }

  const Fraction Fraction::operator+(const Fraction& rhs)
  {
    Fraction z;

    z.den = this->den * rhs.den;
    z.num = (this->num * rhs.den) + (rhs.num * this->den);
    z.reduce_fraction();

    return z;
  }

  const Fraction Fraction::operator-(const Fraction& rhs)
    {
      Fraction z;

      z.den = this->den * rhs.den;
      z.num = (this->num * rhs.den) - (rhs.num * this->den);
      z.reduce_fraction();

      return z;
    }

 std::istream &operator >> (std::istream &is, Fraction& f)
    {
      is >> f.num >> '/' >> f.den;
      if ( den == 0 )
        throw std::invalid_argument("zero denominator");
      f.reduce_fraction();

      return is;
    }

 std::ostream &operator << (std::ostream &os, const Fraction& f)
    {
      if(f.den == 1)
        os << f.num;

      os << f.num << '/' << f.den;

      return os;
    }

  int Fraction::find_gcd (int n1, int n2)
    {
      int gcd, remainder;

      remainder = n1 % n2;
      while ( remainder != 0 )
      {
        n1 = n2;
        n2 = remainder;
        remainder = n1 % n2;
      }
      gcd = n2;

      return gcd;
    }

  void Fraction::reduce_fraction(void)
    {
      int gcd= find_gcd(num, den);
      num = num / gcd;
      den = den / gcd;
      if(den < 0)
      {
        den = -den;
        num = -num;
      }
    }
