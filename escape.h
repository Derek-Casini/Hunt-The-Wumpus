#ifndef ESCAPE_H 
#define ESCAPE_H 

#include "event.h"
#include <iostream>

using namespace std;

class Escape : public Event {
  private: 
  public:
    Escape();
    ~Escape();
    void display_percepts();
    char get_type();
};

#endif