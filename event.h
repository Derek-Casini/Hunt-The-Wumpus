#ifndef EVENT_H
#define EVENT_H 

#include <iostream>

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event {
  protected:
	  const char type;
  public:
    Event();
	  Event(const char);
    virtual ~Event() = 0;
    Event& operator=(Event&);
    virtual char get_type() = 0;
};
#endif