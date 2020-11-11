#include "Car.h"

Car::Car() {
}

Car::~Car() {
}

int Car::getPoints() {
    return 0;
}

void Car::addPoints(int p) {
}

void Car::addPart(Car *part) {
}

void Car::simulate() {
}

int Car::calculateSpeed() {
    return 0;
}

void Car::setRaceTime(int t) {
} // raceTime = param

void Car::incrementRaceTime(int t) {
} //raceTime += param

int Car::getRaceTime() {
    return 0;
}

string Car::getDriverName() {
    return "";
}

void Car::setDriver(Driver *d) {
}

Car* Car::removePart(string part) {
    return NULL;
}

void Car::addTyres(Tyre **t, int num) {
}

void Car::popOldTyre() {
}

Tyre *Car::currentTyre() {
    return nullptr;
}

int Car::getSpeed() {
    return 0;
}