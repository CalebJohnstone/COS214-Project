#include "Engine.h"
#include <iostream>
#include <string>

using namespace std;


Engine::Engine() {
    type = "Engine";
    speed = rand() % 200 + 300;

}

Engine *Engine::cpy() { //might have to make return type Car*
    Engine *temp = new Engine();
    temp->speed = speed;
    temp->next = nullptr;
    return temp;
}

int Engine::getSpeed() {
    return speed;
}

Car* Engine::clone() {
    Engine *temp = cpy();
    if (next != nullptr) {
        temp->next = next->clone();
    }
    return temp;
}