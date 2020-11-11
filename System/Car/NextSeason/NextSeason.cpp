#include "NextSeason.h"

NextSeason::NextSeason() {

}

Car *NextSeason::clone() {
    Car *temp = new NextSeason();
    return temp;
}

string NextSeason::getType() {
    return "base";
}
