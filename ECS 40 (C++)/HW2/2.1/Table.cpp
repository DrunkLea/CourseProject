// Shuyao Li
// 915277384

#include "Table.h"

Table::Table (int n) : maxGuests(n)
{  numGuests = 0; }

int Table::maxOccupancy(void)
{  return maxGuests; }

int Table::currentOccupancy(void)
{  return numGuests;  }

bool Table::addGuests(int n)
{
  if (maxGuests < numGuests + n)
    return false;

  numGuests += n;
  return true;
}
