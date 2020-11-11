#include "Aerodynamics.h"
#include <iostream>
#include <string>
using namespace std;

Aerodynamics::Aerodynamics(){
    type = "Aerodynamics";
    speed = rand() % 500 + 500;

}

Aerodynamics* Aerodynamics::cpy() { //might have to make return type Car*
    Aerodynamics *temp = new Aerodynamics();
    temp->speed = speed;
    temp->next = nullptr;
    return temp;
}

int Aerodynamics::getSpeed() {

    return speed;
}

Car* Aerodynamics::clone() {
    Aerodynamics *temp = cpy();
    if (next != nullptr) {
        temp->next = next->clone();
    }
    return temp;
}