#include "stalactites.h"

using namespace std;

Stalactites::Stalactites() :
    Event('S'){
}

Stalactites::~Stalactites(){
    return;
}

char Stalactites::get_type(){
    return this->type;
}