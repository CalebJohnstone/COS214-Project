#ifndef SHIP_H
#define SHIP_H

#include <string>
#include "Team/Transport/Strategy/TransportStrategy.h"

using namespace std;
/**
 * A class Ship which is a concreteStrategy participant of the strategy design pattern
 * @headerfile Ship.h "Team/Transport/Strategy/Ship.h"
 */
class Ship : public TransportStrategy {

public:
    /**
     *Constructor to create a ship object
     */
    Ship();

/**
 *A function to transport a container, calls containers print function
 * @param container the container object to transport
 */
    void transport(Container *container);
};

#endif
