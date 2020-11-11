#include "Tyre.h"

int Tyre::calculateSpeed(int n) {
	n /= 100;
	n *= getPerformance();
	return n;

}