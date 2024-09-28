#ifndef PLAYER_H
#define PLAYER_H 

#include <string>

using namespace std;

struct Player {
    int x;
    int y;
    int start_x;
    int start_y;
    int armor;
    bool is_alive;
    bool has_gold;
    int confusion;
};

#endif