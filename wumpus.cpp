#include "wumpus.h"

using namespace std;

Wumpus::Wumpus() : 
    Event('W'){
}

Wumpus::~Wumpus(){
    return;
}

char Wumpus::get_type(){
    return this->type;
}