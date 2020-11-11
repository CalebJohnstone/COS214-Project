#include <iostream>
#include "Team/Transport/Container/Box.h"

using namespace std;

Box::Box() : Container(){
  this->setIsBox(true);
}

Box::~Box(){
  //delete items in list
  while (!containers.empty()) {
	  Container* toDelete = containers.back();
	  containers.pop_back();
	  delete toDelete;
  }
}

void Box::add(Container * item){
  containers.push_back(item);
}

void Box::print(){
  cout<<"This box contains:\n";
  for(list<Container*>::iterator i=containers.begin(); i!=containers.end(); ++i){
    (*i)->print();
  }
}
