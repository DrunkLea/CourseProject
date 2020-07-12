// Shuyao Li
// 915277384

#include "Domain.h"
#include<iostream>
#include<vector>
#include <string>


Domain::Domain(void):sizex(600), sizey(500){}
Domain::~Domain(void){
  for(int i = 0; i < s.size(); i++){
    delete s[i];
  }

}
void Domain::addShape(const Shape* p) { s.push_back(p);  }
void Domain::draw(void)
{
std::cout<<"<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>"
"\n<svg width=\"700\" height=\"600\""
"\nxmlns=\"http://www.w3.org/2000/svg\">"
"\n<g transform=\"matrix(1,0,0,-1,50,550)\""
"\nfill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">"
"\n<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"600\" height=\"500\"/>\n";

  for(int i = 0; i < s.size(); i++){
    s[i]->draw();
  }

  Rectangle* plate = new Rectangle(Point(0,0), sizex, sizey);
  std::string diagnostic = "ok";
  for(int i = 0; i < s.size(); i++){
    if (!s[i]->fits_in(*plate)){
      diagnostic = "does not fit";
      break;
    }
    for (int j = i + 1; j < s.size(); j++){
      if (s[i]->overlaps(*s[j])){
        diagnostic = "overlap";
        break;
      }
    }
  }

  std::cout<<
  "</g>\n<g transform=\"matrix(1,0,0,1,50,590)\""
  "\n font-family=\"Arial\" font-size=\"32\">\n<text x=\"0\" y=\"0\">"
  <<diagnostic<<"</text>\n</g>\n</svg>\n";
}
