#include "Driver.h"

#include <string>
Driver::Driver(string n){
	points = 0;
	performance = 0;
	name = n;
}

string Driver::getDriver() { 
	return name; 
}

int Driver::getPerformance() {
	return performance; 
}

void Driver::setPerformance(int p) {
    performance = p;
}

int Driver::getPoints() {
    return points;
}

void Driver::setPoints(int p) {
    points = p;
}

string Driver::getName() {
    return name;
}