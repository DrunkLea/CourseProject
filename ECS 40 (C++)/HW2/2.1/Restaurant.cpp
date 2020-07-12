// Shuyao Li
// 915277384
#include<iostream>
#include <stdexcept>
#include "Restaurant.h"
#include "Table.h"


Restaurant::Restaurant(int nLarge, int nMedium, int nSmall) :size(nLarge + nMedium + nSmall)
{
  tableList = new Table*[size];

  for (int i = 0; i < size; i++) {
    if (i < nLarge){
      tableList[i] = new Table(10);
      std::cout << "Table " << i + 1 << " maximum occupancy 10" << std::endl;
    }
    else if (i < nLarge + nMedium) {
      tableList[i] = new Table(7);
      std::cout << "Table " << i + 1 << " maximum occupancy 7" << std::endl;
    }
    else {
      tableList[i] = new Table(5);
      std::cout << "Table " << i + 1 << " maximum occupancy 5" << std::endl;
    }
  }

}

void Restaurant::addGuests(int nGuests)
{
  if (nGuests <= 0)
    throw std::invalid_argument("must be positive");

  for (int i = 0; i < size; i++){
    if(tableList[i]->addGuests(nGuests)){
      std::cout << nGuests << " guests added to table " << i + 1 << std::endl;
      break;
    }

    if (i == size - 1){
      std::cout << " could not accommodate " << nGuests << " guests" << std::endl;
    }
  }
}

void Restaurant::printSummary(void)
{
  std::cout << "Summary:" << std::endl;
  for (int i = 0; i < size; i++) {
    if (tableList[i]->currentOccupancy()){
      std::cout << "table " << i + 1 << " "
       << tableList[i]->currentOccupancy()<< "/" << tableList[i]->maxOccupancy() << std::endl;
    }
  }
}
