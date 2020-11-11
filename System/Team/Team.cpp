#include "Team.h"
#include "Car/Parts/Aerodynamics.h"
#include "Car/Parts/Electronics.h"
#include "Car/Parts/Engine.h"
#include "Car/Parts/Chassis.h"
#include "Team/Department/AerodynamicsFactory.h"
#include "Team/Department/ChassisFactory.h"
#include "Team/Department/ElectronicsFactory.h"
#include "Team/Department/EngineFactory.h"
#include "Team/Transport/Container/Box.h"
#include "Team/Transport/Container/Equipment.h"
#include "Team/Transport/Strategy/Ship.h"
#include "Team/Transport/Strategy/Truck.h"
#include "Car/CurrentSeason/Tyre/Soft.h"
#include "Car/CurrentSeason/Tyre/Medium.h"
#include "Car/CurrentSeason/Tyre/Hard.h"
#include <iostream>

using namespace std;

Team::Team(string string_name, string driver1Name, string driver2Name) {
    cout << string_name << " has entered the season with drivers " << driver1Name << " and " << driver2Name
         << " on their team" << endl;
    name = string_name;
    currentCars = new Car *[2];

    currentCars[0] = new Aerodynamics();
    currentCars[0]->addPart(new Electronics());
    currentCars[0]->addPart(new Engine());
    currentCars[0]->addPart(new Chassis());
    currentCars[0]->addPart(new CurrentSeason(driver1Name));

    currentCars[1] = currentCars[0]->clone();
    currentCars[1]->setDriver(new Driver(driver2Name));

    nextSeasonCar = new Aerodynamics();
    nextSeasonCar->addPart(new Electronics());
    nextSeasonCar->addPart(new Engine());
    nextSeasonCar->addPart(new Chassis());
    nextSeasonCar->addPart(new NextSeason());

    constructorPoints = 0;
    mediator = new DepartmentMediator(this);
    container = nullptr;
    transportStrategy = nullptr;

    departments = new DepartmentFactory *[4];
    departments[0] = new AerodynamicsFactory(mediator);
    departments[1] = new ChassisFactory(mediator);
    departments[2] = new EngineFactory(mediator);
    departments[3] = new ElectronicsFactory(mediator);
}

void Team::transport() {
cout<<name<<":"<<endl;
    transportStrategy->transport(container);
    cout<<endl;
}

void Team::orderTyres() {

    cout << name << " is ordering tyres" << endl;
    Tyre** t1 = new Tyre*[5];
    Tyre** t2 = new Tyre*[5];
    for(int i=0;i<5;i++){
        int r= rand()%3;
         
        if(r==0){
            //softs
            t1[i] = new Soft();
        }else if(r==1){
//mediums   
             t1[i] = new Medium();
        }else{
//hards   
            t1[i] = new Hard();
        }
      
        int r2=rand()%3;
        if(r2==0){
                    //softs
                    t2[i] = new Soft();
                }else if(r2==1){
        //mediums   
                    t2[i] = new Medium();
                }else{
        //hards   
                    t2[i] = new Hard();
                }

    }

    currentCars[0]->addTyres(t1,5);
    currentCars[1]->addTyres(t2,5);
    cout<<endl;
}

Car **Team::getCurrentSeasonCars() {
    return currentCars;
}

void Team::setEuropeanStrategy() {
    if (transportStrategy) {
        delete transportStrategy;
    }
    if (container) {
        delete container;
    }
    Box *box = new Box();
    box->add(new Equipment("Garage Equipment"));
    box->add(new Equipment("Catering Equipment"));
    box->add(new Equipment("Other Equipment"));
    container = box;
    transportStrategy = new Truck();
}

void Team::setNonEuropeanStrategy() {
    if (transportStrategy) {
        delete transportStrategy;
    }
    if (container) {
        delete container;
    }
    Box *box = new Box();
    box->add(new Equipment("Garage Equipment"));
    box->add(new Equipment("Catering Equipment"));
    box->add(new Equipment("Extra Tools"));
    box->add(new Equipment("Other Equipment"));
    container = box;
    transportStrategy = new Ship();
}

string Team::getName() {
    return name;
}

void Team::upgradeAndSimulate() {
    //cout << "Upgrading car" << endl;
    int u = rand() % 4 + 1;
     
    if (u == 1) {

        departments[0]->createPart(dynamic_cast<DepartmentOutput *>(currentCars[0]),"current");
    } else if (u == 2) {
        departments[1]->createPart(dynamic_cast<DepartmentOutput *>(currentCars[0]),"current");
    } else if (u == 3) {
        departments[2]->createPart(dynamic_cast<DepartmentOutput *>(currentCars[0]),"current");
    } else {
        departments[3]->createPart(dynamic_cast<DepartmentOutput *>(currentCars[0]),"current");
    }

     

    currentCars[0]->simulate();
    currentCars[1]->simulate();


}

void Team::upgradeNextSeason() {
    int u = rand() % 4 + 1;
     
    if (u == 1) {

        departments[0]->createPart(dynamic_cast<DepartmentOutput *>(nextSeasonCar),"next");
    } else if (u == 2) {
        departments[1]->createPart(dynamic_cast<DepartmentOutput *>(nextSeasonCar),"next");
    } else if (u == 3) {
        departments[2]->createPart(dynamic_cast<DepartmentOutput *>(nextSeasonCar),"next");
    } else {
        departments[3]->createPart(dynamic_cast<DepartmentOutput *>(nextSeasonCar),"next");
    }
}

int Team::getConstructorPoints() {
    return constructorPoints;
}

void Team::updatePoints() {
    constructorPoints = currentCars[0]->getPoints() + currentCars[1]->getPoints();
}

Team::~Team() {
    if (transportStrategy) {
        delete transportStrategy;
    }

    for (int i = 0; i < 4; i++) {
        if (departments[i]) {
            delete departments[i];
        }
    }
    delete departments;

    if (mediator) {
        delete mediator;
    }
    if (nextSeasonCar) {
        delete nextSeasonCar;
    }

    for (int i = 0; i < 2; i++) {
        if (currentCars[i]) {
            delete currentCars[i];
        }
    }

    if (container) {
        delete container;
    }

}

void Team::partChanged(DepartmentOutput *part, string season) {
    if (season == "current") {
        cout<<name<<" upgraded "<<part->getType()<< " on current car" << endl;;
        //cout << "partChanged called" << endl;
        currentCars[0] = currentCars[0]->removePart(part->getType());
        //cout << "currentCars[0]: " << currentCars[0] << endl;

        currentCars[1] = currentCars[1]->removePart(part->getType());
        //cout << "after currentCars removing parts" << endl;

        DepartmentOutput *part2 = dynamic_cast<DepartmentOutput *>(part->clone());
    // cout << "after cloning part" << endl;

        currentCars[0]->addPart(part);
        currentCars[1]->addPart(part2);

        //currentCars[0]->printContents();
        //currentCars[1]->printContents();
    } else if (season == "next") {
        cout<<name<<" upgraded "<<part->getType()<< " on next season's car" << endl;;
        nextSeasonCar = nextSeasonCar->removePart(part->getType());
        nextSeasonCar->addPart(part);
    }
    
}





