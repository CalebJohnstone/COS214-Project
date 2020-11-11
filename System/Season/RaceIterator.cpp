#include "Season/RaceIterator.h"

using namespace std;

RaceIterator::RaceIterator(Race** races, int length) {
	this->races = races;
	this->length = length;
	this->current = 0;
}

RaceIterator::~RaceIterator() {}

void RaceIterator::first() {
	current = 0;
}

void RaceIterator::next() {
	if (!isDone()) {
		current++;
	}
}

bool RaceIterator::isDone() {
	return (current == length);
}

Race* RaceIterator::currentItem() {
	if (!isDone()) {
		return races[current];
	} else {
		return NULL;
	}
}