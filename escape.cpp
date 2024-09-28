#include "escape.h"

using namespace std;

Escape::Escape() :
    Event('|'){
}

Escape::~Escape(){
    return;
}

void Escape::display_percepts(){
    return;
}

char Escape::get_type(){
    return this->type;
}