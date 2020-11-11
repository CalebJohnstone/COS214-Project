#include <string>
#include <iostream>
#include "Team/Transport/Strategy/Ship.h"

using namespace std;

Ship::Ship(){

}

void Ship::transport(Container * container){
  cout<<"Transported to race by ship: "<<"\n";
  container->print();
}
