#include "Season/Race.h"
#include "Car/Car.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Race::Race(int l, bool euro, int d, string n, int avgL) {
    european = euro;
    laps = l;
    date = d;
    name = n;
    numCars = 0;
    averageLapTime = avgL;
}

void Race::runRace() {
    for (int i = 0; i < numCars; i++) {
        cars[i]->setRaceTime(i*50);
    }
    cout <<"Starting race: " << RED << name << RESET <<endl;
     cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    
    int halfway=laps/2;
    for (int i = 0; i < laps; i++) {
        for (int j = 0; j < numCars; ++j) {
             int speed=cars[j]->calculateSpeed();
             Tyre* t = cars[j]->currentTyre();

            double time = rand() % 5 + 1000000.0/t->calculateSpeed(speed);
            cars[j]->incrementRaceTime((int) time);
            
        }
        if(i==halfway){
            pitStop(); 
        }
    }
    cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "Race results:" << endl;
    printLeaderBoard();
}

void Race::printLeaderBoard() {
    cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << GREEN;
    sortDrivers();
    for (int i = 0; i < numCars; i++) {
        cout << i+1 << ": " << cars[i]->getDriverName() << endl;
    }
    cout << RESET << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
}

void Race::runQualifying() {
    cout << RED << "Starting Qualifying: " << name << endl;
    for (int i = 0; i < numCars; i++) {
        cars[i]->setRaceTime(0);
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < numCars; ++j) {
            int speed=cars[j]->calculateSpeed();
             Tyre* t = cars[j]->currentTyre();

            double time = rand() % 20 + 1000000.0/t->calculateSpeed(speed);
            cars[j]->incrementRaceTime((int) time);
        }
    }
    for(int i=0;i<numCars;i++){
        cars[i]->popOldTyre();
    }
   
    cout << "Qualifying results: " << RESET << endl;
    printLeaderBoard();
}

void Race::runFreePractice1() {
    cout << RED << "Starting free Practice 1: " << name << endl;

    for (int i = 0; i < numCars; i++) {
        cars[i]->setRaceTime(0);
    }

    for (int j = 0; j < numCars; ++j) {
        int speed=cars[j]->calculateSpeed();
             Tyre* t = cars[j]->currentTyre();

        double time = rand() % 80 + 1000000.0/t->calculateSpeed(speed);
        cars[j]->incrementRaceTime((int) time);
        cars[j]->popOldTyre();
    }

    cout << "Free practice 1 results: " << RESET << endl;
    printLeaderBoard();
}

void Race::pitStop() {
    for (int j = 0; j < numCars; ++j) {
        int time = rand() % 10 + 20;
        cars[j]->incrementRaceTime(time);
        cars[j]->popOldTyre();
        cout << cars[j]->getDriverName() << " had a pit stop time of " << time <<"s"<< endl;
    }
}

int Race::getDate() {
    return date;
}

bool Race::isEuropean() {
    return european;
}


void Race::runFreePractice2() {
    cout << RED << "Starting free Practice 2: " << name << endl;

    for (int i = 0; i < numCars; i++) {
        cars[i]->setRaceTime(0);
    }

    for (int j = 0; j < numCars; ++j) {
        int speed=cars[j]->calculateSpeed();
        Tyre* t = cars[j]->currentTyre();

        double time = rand() % 60 + 1000000.0/t->calculateSpeed(speed);
        cars[j]->incrementRaceTime((int) time);
        cars[j]->popOldTyre();
    }

    cout << "Free practice 2 results: " << RESET << endl;
    printLeaderBoard();
     
}

void Race::runRaceWeekend(Car **c, int num) {
    numCars = num;
    cars = c;

    for (int i = 0; i < numCars; i++) {
        cars[i]->setRaceTime(0);
    }
    cout << RED << "Race weekend for race:" << name << " is starting" << RESET << endl;
        cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout<< BLUE << "Number of laps: "<<laps<<endl;
    cout<<"Average Lap Time: "<<averageLapTime<<"s"<< RESET << endl;
         cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    runFreePractice1();
    runFreePractice2();
    runQualifying();
    runRace();
    allocatePoints();
    cout << RED << "Race weekend for race:" << name << " has ended" <<  RESET << endl;

}


void Race::sortDrivers() {
    for (int i = 0; i < numCars; i++) {
        for (int j = i; j < numCars; j++) {
            if (cars[i]->getRaceTime() > cars[j]->getRaceTime()) {
                Car *temp = cars[i];
                cars[i] = cars[j];
                cars[j] = temp;
            }
        }
    }
}

void Race::allocatePoints() {
    sortDrivers();
    cars[0]->addPoints(25);
    cars[1]->addPoints(18);
    cars[2]->addPoints(15);
    cars[3]->addPoints(12);
    cars[4]->addPoints(10);
    cars[5]->addPoints(8);
    cars[6]->addPoints(6);
    cars[7]->addPoints(4);
    cars[8]->addPoints(2);
    cars[9]->addPoints(1);

}

string Race::getName() {
    return name;
}
