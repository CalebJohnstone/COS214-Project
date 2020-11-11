#include "Electronics.h"
#include <iostream>
#include <string>

using namespace std;


Electronics::Electronics() {
    speed = rand() % 5 + 10;
    type = "Electronics";
}

Electronics *Electronics::cpy() { //might have to make return type Car*
    Electronics *temp = new Electronics();
    temp->speed = speed;
    temp->next = nullptr;
    return temp;
}

int Electronics::getSpeed() {
    return speed;
}

Car* Electronics::clone() {
    Electronics *temp = cpy();
    if (next != nullptr) {
        temp->next = next->clone();
    }
    return temp;
}