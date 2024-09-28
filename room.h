#ifndef ROOM_H
#define ROOM_H 

#include <iostream>
#include "event.h"
#include "gold.h"
#include "wumpus.h"
#include "passage.h"
#include "stalactites.h"
#include "escape.h"
#include "bats.h"
#include "armor.h"
#include <ncurses.h>

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room{
  private: 
    Event* e;
    WINDOW* w;
  public:
    Room();
    Room(char);
    ~Room();
	  void set_event(char);
    bool has_event();
    char get_event();
    void set_window(WINDOW*);
    WINDOW* get_window();
    void display_percepts();
};

#endif