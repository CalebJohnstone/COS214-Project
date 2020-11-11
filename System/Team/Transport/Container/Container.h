#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>


using namespace std;
/**
 * A class Container that is the Component of the Composite design pattern.
 * @headerfile Container.h "Team/Transport/Container/Container.h"
 */
class Container {
private:
    bool isBox;/*! @var true indicates that it is a box object */
public:
    /**
     *Constructor to create the container object
     */
    Container();

    /**
     *Destructor to destroy the container object
     */
    virtual ~Container();

    /**
     *Function to print the contents of the container
     */
    virtual void print() = 0;

    /**
     *Function that sets the boxes isBox variable
     * @param b takes a boolean as parampter
     */
    void setIsBox(bool b);

    /**
     *Function that returns the boxes isBox varaible
     * @return boolean 
     */
    bool getIsBox();


};

#endif
