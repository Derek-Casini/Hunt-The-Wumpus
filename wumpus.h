#ifndef WUMPUS_H
#define WUMPUS_H 

#include "event.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

class Wumpus : public Event {
  private: 
  public:
    Wumpus();
    ~Wumpus();
    char get_type();
};


#endif