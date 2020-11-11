#ifndef EQUIPMENT_H
#define EQUIPMENT_H


#include <string>
#include "Team/Transport/Container/Container.h"


using namespace std;
/**
 * The Leaf component of the Composite design pattern. Represents a single piece of equipment that must be transported to a race.
 * @headerfile Equipment.h "Team/Transport/Container/Equipment.h"
 */
class Equipment : public Container {
private:
    string name;/*! @var the name of the equipment.*/
public:
    /**
     * 
     * @param name The name of the equipment.
     */
    Equipment(string name);

    /**
     * Prints the name of the equipment.
     */
    void print();

};

#endif
