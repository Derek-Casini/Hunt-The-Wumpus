#include "room.h"

using namespace std;

//Room Implementation
Room::Room(){
        e = nullptr;
}

Room::Room(char type){
    if(type == 'g'){
        e = new Gold();
    }
    else if(type == 'w'){
        e = new Wumpus();
    }
    else if(type == 's'){
        e = new Stalactites();
    }
    else if(type == '|'){
        e = new Escape();
    }
    else if(type == 'b'){
        e = new Bats();
    }
    else if(type == 'a'){
        e = new Armor();
    }
    else if(type == 'p'){
        e = new Passage();
    }
}

Room::~Room(){
    delete e;
    e = nullptr;
}


void Room::set_event(char type){
    if(type == 'g'){
        e = new Gold();
    }
    else if(type == 'w'){
        e = new Wumpus();
    }
    else if(type == 's'){
        e = new Stalactites();
    }
    else if(type == '|'){
        e = new Escape();
    }
    else if(type == 'b'){
        e = new Bats();
    }
    else if(type == 'a'){
        e = new Armor();
    }
    else if(type == 'p'){
        e = new Passage();
    }
}

bool Room::has_event(){
    if(e != nullptr){
        return true;
    }
    return false;
}

char Room::get_event(){
    char type = (*e).get_type();
    return type;
}

void Room::set_window(WINDOW* win){
    this->w = win;
}

WINDOW* Room::get_window(){
    return w;
}

void Room::display_percepts(){
    if(Room::get_event() == 'W'){
		printw("You smell a terrible stench.\n");
	}
	if(Room::get_event() == 'S'){
		printw("You hear water dripping.\n");
	}
	if(Room::get_event() == 'G'){
		printw("You see a glimmer nearby.\n");
	}
	if(Room::get_event() == 'B'){
        printw("You hear wings flapping.\n");
	}
    if(Room::get_event() == 'A'){
        printw("You feel the power.\n");
    }
    if(Room::get_event() == 'P'){
        printw("You feel a breeze.\n");
    }
}