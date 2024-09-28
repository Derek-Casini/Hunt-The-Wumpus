#ifndef STALACTITES_H
#define STALACTITES_H 
#include "event.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

class Stalactites : public Event {
  private: 
  public:
    Stalactites();
    ~Stalactites();
    char get_type();
};


#endif
