#include "Team/Department/DepartmentFactory.h"

DepartmentFactory::DepartmentFactory(DepartmentMediator* mediator) : mediator(mediator) {
    mediator->attachDepartment(this);
}

DepartmentFactory::~DepartmentFactory(){
    //Team is responsible for de-allocating the mediator
    
}

int DepartmentFactory::getPartSpeed(Car* oldPart, string partType){
    if(oldPart->getType() == partType){
        return oldPart->getSpeed();
    }else{
        return getPartSpeed(dynamic_cast<DepartmentOutput*>(oldPart)->getNext(), partType);
    }
}