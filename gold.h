#ifndef GOLD_H
#define GOLD_H 

#include <iostream>
#include <ncurses.h>
#include "event.h"

using namespace std;

class Gold : public Event {
  private: 
  public:
    Gold();
    ~Gold();
    char get_type();
};

#endif