#ifndef PASSAGE_H
#define PASSAGE_H

#include "event.h"
#include <ncurses.h>

using namespace std;

class Passage : public Event {
  private:
  public:
    Passage();
    ~Passage();
    char get_type();
};


#endif