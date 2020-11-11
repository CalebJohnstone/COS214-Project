#include "DepartmentOutput.h"

#include <string>
#include <iostream>

using namespace std;

DepartmentOutput::DepartmentOutput() {
    next = nullptr;
    type = "";
    //averageSpeed = 0;
}

Car* DepartmentOutput::removePart(string part) {

    if (type == part) {
      
        Car *temp = next;
        next = NULL;
        delete this;
        return temp;
    } else {
        next = next->removePart(part);
        return this;
    }
    /*
    if (next != nullptr && (next->getType()) != "current") {
        DepartmentOutput *n = (dynamic_cast<DepartmentOutput *> (next));
        if (n->getType() == part) {
            DepartmentOutput *temp = n;
            this->next = temp->next; //removes it from the list
            temp->removePart(part); //calls the concrete removePart() for the cout
            delete temp;
        }
    } else cout << part << " could not be found." << endl;*/
}


void DepartmentOutput::addPart(Car *part) {
    if (next != nullptr) {
        if ((next->getType()) != "base") //if next is not CurrentSeason type
            next->addPart(part);
        else {
            DepartmentOutput *p = dynamic_cast<DepartmentOutput *>(part);
            p->next = next;
            next = p;
        }
    } else next = part;
    //cout << "Part: " << part->getType() << " added" << endl;
}

int DepartmentOutput::calculateSpeed() {
    int averageSpeed = 0;
    int s = this->getSpeed();

    int rtrn;
    if (next != nullptr) {
        /*if ((next->getType()) != "base") {
            averageSpeed += s + next->calculateSpeed();
            rtrn = averageSpeed;
        } else {
            averageSpeed += s + next->calculateSpeed();
            rtrn = averageSpeed;

        }
         */
        averageSpeed += s + next->calculateSpeed();
        rtrn = averageSpeed;

    }
    return rtrn;
}

DepartmentOutput::~DepartmentOutput() {
    if (next != NULL) {
        delete next;
    }
}

void DepartmentOutput::setRaceTime(int rt) {
    next->setRaceTime(rt);

}

void DepartmentOutput::incrementRaceTime(int rt) {
    next->incrementRaceTime(rt);
}

int DepartmentOutput::getRaceTime() {
    return next->getRaceTime();
}

void DepartmentOutput::setDriver(Driver *d) {
    next->setDriver(d);
}

int DepartmentOutput::getPoints() {
    return next->getPoints();
}

void DepartmentOutput::addPoints(int p) {
    next->addPoints(p);
}

void DepartmentOutput::simulate() {
    next->simulate();
}

string DepartmentOutput::getDriverName() {
    return next->getDriverName();
}


int DepartmentOutput::getSpeed() {
    return speed;
}

void DepartmentOutput::addTyres(Tyre **t, int num) {
    next->addTyres(t, num);
}

void DepartmentOutput::popOldTyre() {
    next->popOldTyre();
}

Tyre *DepartmentOutput::currentTyre() {
    return next->currentTyre();
}

Car *DepartmentOutput::getNext() {
    return next;
}

string DepartmentOutput::getType(){
    return type;
}

