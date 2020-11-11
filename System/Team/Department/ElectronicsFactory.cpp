#include "Team/Department/ElectronicsFactory.h"
#include <iostream>
ElectronicsFactory::ElectronicsFactory(DepartmentMediator* mediator) : DepartmentFactory(mediator){

}

ElectronicsFactory::~ElectronicsFactory(){

}
    
void ElectronicsFactory::createPart(DepartmentOutput* oldPart,string season){
    //create new part
    Electronics* part = new Electronics();
    //cout << "Creating electronics part" << endl;
    //determine if the part could be better
    //give 20% chance for part to be better,  part is not better iff (speed <= 0)
    if (part->getSpeed() > getPartSpeed(oldPart, "Electronics")) {
        //tell other departments that the new part is better, the team will add the part when it is passed to it by: team->partChanged(part);
        mediator->communicate(part,season);
    } else {
        //de-allocate part
        delete part;
    }


}

void ElectronicsFactory::simulation(){
    cout << "The driver is using the simulator to test the electronics, so they are familiar with the controls." << endl;
}

void ElectronicsFactory::otherPartChanged(DepartmentOutput* part){
    cout << "The Electronics department confirms that they have received the message about the new " << part->getType() << endl;
}

string ElectronicsFactory::getType(){
    return "Electronics";
}