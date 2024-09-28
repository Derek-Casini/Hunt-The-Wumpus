#include "armor.h"

using namespace std;

Armor::Armor() : 
    Event('A'){
}

Armor::~Armor(){
    return;
}

char Armor::get_type(){
    return this->type;
}