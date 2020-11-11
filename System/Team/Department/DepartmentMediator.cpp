#include "Team/Department/DepartmentMediator.h"
#include <iostream>

DepartmentMediator::DepartmentMediator(Team* team): team(team), currentDepartment(0){
    //initialise array of DepartmentFactories
    departments = new DepartmentFactory*[4];

    for(int i = 0; i < 4; ++i){
        departments[i] = nullptr;
    }
}

DepartmentMediator::~DepartmentMediator(){
    
}

void DepartmentMediator::communicate(DepartmentOutput* part,string season){
    string partString = part->getType();
    //tell the Team
    team->partChanged(part,season);
    for(int i = 0; i < 4; ++i){
        //tell all other departments of the newly added part
        if(departments[i]->getType() != partString){
            departments[i]->otherPartChanged(part);
        }
    }

    
}

void DepartmentMediator::attachDepartment(DepartmentFactory* department){
    if(currentDepartment < 4){
        departments[currentDepartment++] = department;
    }else{
        cout << "A department mediator can only mediate for a maximum of 4 departments" << endl;
    }
}