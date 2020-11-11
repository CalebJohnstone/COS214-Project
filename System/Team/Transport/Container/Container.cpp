#include <string>
#include "Team/Transport/Container/Container.h"
#include <iostream>

using namespace std;

Container::Container(){}

Container::~Container(){}

void Container::setIsBox(bool b){
  isBox=b;
}

bool Container::getIsBox(){
  return isBox;
}
