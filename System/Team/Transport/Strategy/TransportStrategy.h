#ifndef TRANSPORTSTRATEGY_H
#define TRANSPORTSTRATEGY_H

#include <string>
#include "Team/Transport/Container/Container.h"

using namespace std;
/**
 * The Strategy participant of the Strategy design pattern. Base class for several strategies of transporting items to races.
 * @headerfile TransportStrategy.h "Team/Transport/Strategy/TransportStrategy.h"
 */
class TransportStrategy {

public:
    /**
     * Default constructor.
     */
    TransportStrategy();

/**
 * Pure virtual function for transporting items.
 * @param container The container to be transported.
 */
    virtual void transport(Container *container) = 0;
};

#endif
