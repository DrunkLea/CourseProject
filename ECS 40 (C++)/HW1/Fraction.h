// Shuyao Li
// 915277384
// Fraction.h

#ifndef FRACTION_H
#define FRACTION_H

#include<iostream>
class Fraction
{
  public:
    Fraction(void);
     Fraction(int a, int b);
    ~Fraction(void);
    int getNum(void) const;
    int getDen(void) const;
    Fraction operator= (const Fraction &f);
    const Fraction operator+(const Fraction &f);
    const Fraction operator-(const Fraction &f);
    friend std::ostream& operator <<(std::ostream& os, Fraction &f);
    friend std::istream& operator >>(std::istream& is, const Fraction &f);
  private:
    int find_gcd (int a, int b);
    void reduce_fraction(void);
    int num, den;
};

#endif
