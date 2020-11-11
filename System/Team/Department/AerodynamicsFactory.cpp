#include "Team/Department/AerodynamicsFactory.h"
#include <iostream>

AerodynamicsFactory::AerodynamicsFactory(DepartmentMediator* mediator) : DepartmentFactory(mediator){
    windTokens = 400;
}

AerodynamicsFactory::~AerodynamicsFactory(){

}

void AerodynamicsFactory::createPart(DepartmentOutput* oldPart,string season){
    //create new part
    //cout << "Creating aerodynamic part" << endl;
    Aerodynamics* newPart = new Aerodynamics();

    //determine if the part could be better
    //give 20% chance for part to be better, part is not better iff (speed <= 0) -> no need to test in the windTunnel
    if(newPart->getSpeed() > getPartSpeed(oldPart, "Aerodynamics")){
        //we know the part is better in theory, but is it better in practice -> use wind tunnel
        int windPerformance = windTunnel();

        //10% chance that has better wind performance than current part
        if (windPerformance >= 0 && windPerformance < 10) {
            //tell other departments that the new part is better, the team will add the part when it is passed to it by: team->partChanged(part);
            mediator->communicate(newPart,season);
        } else {
            //de-allocate part
            delete newPart;
        }
    } else {
        //de-allocate part
        delete newPart;
    }


}

void AerodynamicsFactory::simulation(){
    cout << "The driver is using the simulator to see the weather conditions and wind patterns predicted for the race." << endl;
}

void AerodynamicsFactory::otherPartChanged(DepartmentOutput* part){
    cout << "The Aerodynamics department confirms that they have received the message about the new " << part->getType() << endl;
}

int AerodynamicsFactory::windTunnel(){
    if(windTokens == 0){
        cout << "The team is out of wind tunnel tokens for the season. They can therefore not use the tunnel anymore this season." << endl;
        return -1;
    }else{
        decreaseTunnelTokens();
        return rand() % 100;
    }
}

int AerodynamicsFactory::getTunnelTokens(){
    return windTokens;
}

void AerodynamicsFactory::decreaseTunnelTokens(){
    --windTokens;
}

string AerodynamicsFactory::getType(){
    return "Aerodynamics";
}