#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include "Team/Transport/Strategy/TransportStrategy.h"

using namespace std;
/**
 * A class Truck which is a concreteStrategy participant of the strategy design pattern
 * @headerfile Truck.h "Team/Transport/Strategy/Truck.h"
 */
class Truck : public TransportStrategy {

public:
    /**
     *A constructor to create a Truck object
     */
    Truck();

    /**
     *A function to transport a container, it calls the containers print function
     * @param container
     */
    void transport(Container *container);
};

#endif
