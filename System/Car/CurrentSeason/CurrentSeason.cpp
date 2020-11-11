#include "CurrentSeason.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

CurrentSeason::CurrentSeason(string n){
    raceTime = 0;
    //tyres = new Tyres();
    driver = new Driver(n);
    srand(time(0));
}

void CurrentSeason::addPoints(int p){
    driver->setPoints(driver->getPoints() + p);
}

void CurrentSeason::simulate() {    // each call of this function has on average 10% chance to increase performance by 1
    int improvement = 0;
    for (int j = 0; j < 5; j++) {
        int i = (rand() % 30 + 1);
        switch (i) {
            case 1:
                improvement++;
            default:
                break;
        }
    }
    if (improvement > 0) {
        cout<<driver->getName()<<" gained experience: "<<improvement<<endl;
        driver->setPerformance(driver->getPerformance() + improvement);
    }
}

int CurrentSeason::getPoints() {
    return driver->getPoints();
}



int CurrentSeason::calculateSpeed() {    
    return driver->getPerformance();
}

Car *CurrentSeason::clone() {
    Car *temp = new CurrentSeason(driver->getName());
    return temp;
}

string CurrentSeason::getDriverName() {
    return driver->getDriver();
}

CurrentSeason::~CurrentSeason() {
    delete driver;
    //delete the tyres too
}

void CurrentSeason::setRaceTime(int rt) {
    raceTime = rt;
}

void CurrentSeason::incrementRaceTime(int rt) {
    raceTime += rt;
}

int CurrentSeason::getRaceTime() {
    return raceTime;
}

void CurrentSeason::setDriver(Driver *d) {
    driver = d;
}

string CurrentSeason::getType() {
    return "base";
}

void CurrentSeason::addTyres(Tyre** t, int num) {
    for(int i=0;i<num;i++){
        tyres.push(t[i]);
    }
}

void CurrentSeason::popOldTyre() {
    delete tyres.front();
    tyres.pop();
}

Tyre* CurrentSeason::currentTyre() {
    return tyres.front();
}
