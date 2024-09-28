#ifndef GAME_H
#define GAME_H 

#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"
#include "player.h"
#include "escape.h"
#include "armor.h"
#include "room.h"
#include "passage.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <ncurses.h>

using namespace std;

//Game interface 
class Game {
private:
	int length; 			//length of the board
	int width;  			//width of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not
	bool w_alive;
	int passage_coords[4];
	vector<vector<Room*>> game_board;
	vector<vector<Room*>> visable_game_board;
	vector<vector<Room*>> game_board_at_start;
	Player p;
public:
	Game();
	~Game();
	void init_boards();
	void init_player();
	void get_random_coord(int&);
	bool has_player(int, int);
	void swap_at(int, int, Room*);
	void set_up(int, int);
	void display_game() const;
	void display_game_debug() const;
	bool check_win() const;
	char get_dir();
	void wumpus_move();
	void handle_arrow(int, int, bool);
	void fire_arrow();
	void move_up();
	void move_down();
	void move_left();
	void move_right();
	void handle_movement(char);
	void move(char);
	void check_death();
	void handle_event();
	char get_input();
	void reset_game(bool, int, int);
	void handle_percepts(bool, int, int);
	void display_percepts();
	void play_game(int, int, bool, bool);
};
#endif