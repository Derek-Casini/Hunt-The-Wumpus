#include "event.h"

using namespace std;

//Event Implementation
Event::Event() : 
    type(' '){ 
}

Event::~Event(){
}

Event::Event(const char t) :
    type(t){
}
