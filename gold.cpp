#include "gold.h"

using namespace std;

Gold::Gold() : 
    Event('G'){
}

Gold::~Gold(){
    return;
}

char Gold::get_type(){
    return this->type;
}