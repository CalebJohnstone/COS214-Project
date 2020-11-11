#include "Chassis.h"
#include <iostream>
#include <string>
using namespace std;

Chassis::Chassis(){
    speed = rand() % 100 + 150;
    type = "Chassis";
}

Chassis* Chassis::cpy() { //might have to make return type Car*
    Chassis *temp = new Chassis();
    temp->speed = speed;
    temp->next = nullptr;
    return temp;
}

int Chassis::getSpeed(){
    return speed;
}

Car* Chassis::clone() {
    Chassis *temp = cpy();
    if (next != nullptr) {
        temp->next = next->clone();
    }
    return temp;
}