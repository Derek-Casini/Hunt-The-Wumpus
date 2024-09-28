#ifndef ARMOR_H
#define ARMOR_H

#include "event.h"
#include <ncurses.h>

using namespace std;

class Armor : public Event {
  private: 
  public:
    Armor();
    ~Armor();
    char get_type();
};


#endif