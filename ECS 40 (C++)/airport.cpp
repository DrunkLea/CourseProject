// Shuyao Li
// 915288384

#include "Code.h"
#include "Facility.h"
#include "Runway.h"
#include "SiteNumber.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>


int main(int argc, char **argv)
{
  std::string code = argv[1];
  std::cout<<"size="<<code.size()<<std::endl;
  if (code.size() > 4){
    std::cout<<"Airport code must be at most 4 characters"<<std::endl;
    return 1;
  }
  std::string line;
  if(code.size() == 3){
    code += " ";std::cout<<"blank added"<<std::endl;
  }
  std::ifstream facilities_file("Facilities.txt");
  std::vector<Facility*> fv(19700);
  std::vector<Facility*>::iterator f_iter;
  for (f_iter = fv.begin(); f_iter != fv.end(); f_iter++){
    getline(facilities_file,line);
    *f_iter = new Facility(line);
  }
  std::cout<<"airports created"<<std::endl;
  f_iter = find_if(fv.begin(), fv.end(), Code(*f_iter);
  if(f_iter == fv.end()){
    std::cout<<code<<" not found"<<std::endl;
    return 1;
  }


/ for (f_iter = fv.begin(); f_iter != fv.begin()+5; f_iter++){
    std::cout << *f_iter << std::endl;
    }

 std::cout << *f_iter.site_number() << " " << *f_iter.Facility::code() << " "
  << *f_iter.Facility::name() << std::endl;

  std::ifstream runways_file("Runways.txt");
  std::vector<Runway*> rv(23595);
  std::vector<Runway*>::iterator r_iter;
  //std::vector<Runway*> desired_rv;
  for (r_iter = rv.begin(); r_iter != rv.end(); r_iter++){
    getline(runways_file,line);
    *r_iter = new Runway(line);
  }
  stable_partition(rv.begin(),rv.end(),SiteNumber<Runway>(f_iter->site_number())(*r_iter));
  r_iter = rv.begin();
  while (!(f_iter->site_number()).compare(r_iter->site_number())){
    std::cout<<r_iter->site_number()<<" "<<r_iter->name()<<" "<<r_iter->length()<<std::endl;
  }

}
