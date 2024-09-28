#include "passage.h"

using namespace std;

Passage::Passage() :
    Event('P'){  
    }

Passage::~Passage(){
    return;
}

char Passage::get_type(){
    return this->type;
}