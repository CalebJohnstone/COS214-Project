#ifndef BOX_H
#define BOX_H

#include <string>
#include <list>
#include "Team/Transport/Container/Container.h"

using namespace std;
/**
 * A class Box that is the composite participant of the composite design pattern
 * @headerfile Box.h "Team/Transport/Container/Box.h"
 */
class Box : public Container {
private:
    list<Container *> containers;/*! @var List of the containers inside the box*/
public:
    /**
     *Constructor to create a box object
     */
    Box();

    /**
     *Destructor to destroy the box object
     */
    ~Box();

    /**
     *Function to add a container to the box
     * @param item Container to add
     */
    void add(Container *item);

    /**
     *Function to print the contents of the box
     */
    void print();
};

#endif
