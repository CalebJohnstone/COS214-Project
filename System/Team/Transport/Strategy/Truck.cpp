#include <string>
#include <iostream>
#include "Team/Transport/Strategy/Truck.h"

using namespace std;

Truck::Truck(){

}

void Truck::transport(Container * container){
  cout<<"Transported to race by truck: "<<"\n";
  container->print();
}
