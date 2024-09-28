#ifndef BATS_H
#define BATS_H 

#include "event.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

class Bats : public Event {
  private: 
  public:
    Bats();
    ~Bats();
    char get_type();
};


#endif