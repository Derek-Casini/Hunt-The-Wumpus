#include "bats.h"

using namespace std;

Bats::Bats() : 
    Event('B'){
}

Bats::~Bats(){
    return;
}

char Bats::get_type(){
    return this->type;
}