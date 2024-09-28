#include "game.h"

using namespace std;

//Game Implementation

Game::Game() :
	length(0), width(0){
	this->num_arrows = 3;
	this->w_alive = true;
	initscr();
	noecho();
}

Game::~Game(){
	for(int i = 0; i < width; i++){
		for(int j = 0; j < length; j++){
			delete game_board[i][j];
			game_board[i][j] = nullptr;
		}
	}
}

void Game::init_boards(){
	vector<vector<Room*> > temp(width);
	for(int i = 0; i < width; i++){
		for(int j = 0; j < length; j++){
			temp.at(i).push_back(new Room());
			temp[i][j]->set_window(newwin(7, 14, i * 7, j * 15));
		}
	}
	refresh();
	game_board = temp;
	visable_game_board = temp;
}

void Game::init_player(){
	int x = 0, y = 0; 
	if(width > 0){
		x = rand() % width;
	}
	if(length > 0){
		y = rand() % length;
	}
	p.x = x;
	p.y = y;
	p.start_x = x;
	p.start_y = y;
	p.has_gold = false;
	p.is_alive = true;
	p.confusion = 0;
	p.armor = 0;
}

bool Game::has_player(int x, int y){
	if(p.x == x && p.y == y){
		return true;
	}
	return false;
}

void Game::get_random_coord(int& c){
	int x = rand() % width;
	int y = rand() % length;
	while(has_player(x,y) || game_board[x][y]->has_event()){
		if(!has_player(x,y) && !game_board[x][y]->has_event()){
			break;
		}
		y = rand() % length;
		x = rand() % width;
	}
	(&c)[0] = x;
	(&c)[1] = y;
}

void Game::swap_at(int x, int y, Room* r){
	r->set_window(game_board.at(x).at(y)->get_window());
	game_board[x][y] = r;
}

void Game::set_up(int l, int w){
	this->length = l;
	this->width = w;
	this->num_arrows = 3; //start with 3 arrows
	init_boards();
	init_player();
	swap_at(p.x, p.y, new Room('|'));
	int cindex = 0;
	int coord[2];
	for(int i = 0; i < 2; i++){
		get_random_coord(*coord);
		swap_at(coord[0], coord[1], new Room('s'));
		get_random_coord(*coord);
		swap_at(coord[0], coord[1], new Room('b'));
		get_random_coord(*coord);
		swap_at(coord[0], coord[1], new Room('p'));
		passage_coords[cindex] = coord[0];
		cindex++;
		passage_coords[cindex] = coord[1];
		cindex++;
	}
	get_random_coord(*coord);
	swap_at(coord[0], coord[1], new Room('g'));
	get_random_coord(*coord);
	swap_at(coord[0], coord[1], new Room('w'));
	get_random_coord(*coord);
	swap_at(coord[0], coord[1], new Room('a'));
	game_board_at_start = game_board;
}


//Note: you need to modify this function
void Game::display_game() const{
	for(int i = 0; i < width; i++){
		for(int j = 0; j < length; j++){
			WINDOW* temp = this->visable_game_board[j][i]->get_window();
			werase(temp);
			box(temp, 0, 0);
			if(i == p.y && j == p.x){
				mvwaddch(temp, 4, 7, '*');
				if(this->game_board[j][i]->has_event()){
					mvwaddch(temp, 3, 7, game_board[j][i]->get_event());
				}
			}
			wnoutrefresh(temp);
		}
	}
	string str = "W-up A-left S-down D-right F-fire an arrow		Arrows remaining: " + to_string(num_arrows) + '\n';
	mvprintw(length*width + 12, 0, str.c_str());
	refresh();
	doupdate();
}

void Game::display_game_debug() const{
	for(int i = 0; i < width; i++){
		for(int j = 0; j < length; j++){
			WINDOW* temp = this->game_board[i][j]->get_window();
			werase(temp);
			box(temp, 0, 0);
			if(this->game_board[i][j]->has_event()){
				mvwaddch(temp, 3, 7, game_board[i][j]->get_event());
			}
			if(j == p.y && i == p.x){
				mvwaddch(temp, 4, 7, '*');
			}
			wnoutrefresh(temp);
		}
	}
	string str = "W-up A-left S-down D-right F-fire an arrow		Arrows remaining: " + to_string(num_arrows) + '\n';
	mvprintw(length*width + 10, 0, str.c_str());
	refresh();
	doupdate();
}

bool Game::check_win() const{
	if(game_board[p.x][p.y]->has_event()){
		if((game_board[p.x][p.y]->get_event() == '|' && p.has_gold) || !this->w_alive){
			return true;
		}
	}
	else if(!this->w_alive){
		return true;
	}
	return false;
}

void Game::move_up() {
	if(p.x - 1 >= 0){
		p.x--;
	}
}

void Game::move_down() {
	if(p.x + 1 < width){
		p.x++;
	}
}

void Game::move_left() {
	if(p.y - 1 >= 0){
		p.y--;
	}
}

void Game::move_right() {
	if(p.y + 1 < length){
		p.y++;
	}
}

char Game::get_dir(){
	//get direction of arrow:
	char dir;
	//Note: error checking is needed!! 
	//Your code here:
	printw("\nFire an arrow . . .\n");
	printw("W-up\n");
	printw("A-left\n");
	printw("S-down\n");
	printw("D-right\n");
	printw("Enter direction: ");
	dir = getch();
	while(dir != 'w' && dir != 'a' && dir != 's' && dir != 'd'){
		printw("\nInvalid argument \nEnter direction: ");
		dir = getch();
	}
	refresh();
	return dir;
}

void Game::wumpus_move(){
	int rng = rand() % 3;
	if(rng != 0){
		for(int i = 0; i < width; i++){
			for(int j = 0; j < length; j++){
				if(game_board[i][j]->has_event()){
					if(game_board[i][j]->get_event() == 'W'){
						swap_at(i, j, new Room());
					}
				}
			}
		}
		int coord[2];
		get_random_coord(*coord);
		swap_at(coord[0], coord[1], new Room('w'));
	}
}

void Game::handle_arrow(int x, int y, bool b){
	if(b){
		if(game_board[x][y]->has_event()){
			if(game_board[x][y]->get_event() == 'W'){
				w_alive = false;
			}
		}
	}
}


void Game::fire_arrow(){
	// The player may fire arrow...
	if(num_arrows > 0){
		char dir = get_dir();
		for(int i = 1; i < 4; i++){
			if(dir == 'w'){
				handle_arrow(p.x - i, p.y, p.x - i >= 0);
			}
			if(dir == 'a'){
				handle_arrow(p.x, p.y - i, p.y - i >= 0);
			}
			if(dir == 's'){
				handle_arrow(p.x + i, p.y, p.x + i < width);
			}
			if(dir == 'd'){
				handle_arrow(p.x, p.y + i, p.y + i < length);
			}
		}
		num_arrows--;
		clear();
		refresh();
	}
	else{
		printw("\nYou have no arrows remaining!\n Press any key to continue . . .");
		getch();
		clear();
		refresh();
	}
}

void Game::check_death(){
	if(p.armor > 0){
		p.armor--;
	}
	else{
		p.is_alive = false;
	}
}

void Game::handle_event(){
	if(game_board[p.x][p.y]->has_event()){
		if(game_board[p.x][p.y]->get_event() == 'B'){
			p.confusion = 5;
		}
		else if(game_board[p.x][p.y]->get_event() == 'G'){
			p.has_gold = true;
			swap_at(p.x, p.y, new Room());
		}
		else if(game_board[p.x][p.y]->get_event() == 'S'){
			int rng = rand() % 2;
			if(rng == 0){
				check_death();
			}
			else{
				wumpus_move();
			}
		}
		else if(game_board[p.x][p.y]->get_event() == 'W'){
			check_death();
		}
		else if(game_board[p.x][p.y]->get_event() == 'A'){
			p.armor = 2;
			swap_at(p.x, p.y, new Room());
		}
		else if(game_board[p.x][p.y]->get_event() == 'P'){
			if(p.x == passage_coords[0] && p.y == passage_coords[1]){
				p.x = passage_coords[2];
				p.y = passage_coords[3];
			}
			else{
				p.x = passage_coords[0];
				p.y = passage_coords[1];
			}
		}
	}
	return;
}

void Game::handle_movement(char c){
	switch(c){
			case 'w':
				Game::move_up();
				handle_event();
				break;
			case 'a':
				Game::move_left();
				handle_event();
				break;
			case 's':
				Game::move_down();
				handle_event();
				break;
			case 'd':
				Game::move_right();
				handle_event();
				break;
		}
}

void Game::move(char c) {
	if (c == 'f'){
		Game::fire_arrow();
		return;
	}
	if(p.confusion > 0){
		switch(c){
			case 'w':
				handle_movement('s');
			case 'a':
				handle_movement('d');
			case 's':
				handle_movement('w');
			case 'd':
				handle_movement('a');
		}
		p.confusion--;
	}
	else{
		handle_movement(c);
	}
}

char Game::get_input(){
	char c;
	c = getch();
	return c;
}

void Game::reset_game(bool a, int w, int l){
	if(!a){
		Game::set_up(w, l);
	}
	else{
		game_board = game_board_at_start;
		this->num_arrows = 3;
	}
	p.is_alive = true;
	this->w_alive = true;
	p.has_gold = false;
	p.x = p.start_x;
	p.y = p.start_y;
	p.armor = 0;
	clear();
	refresh();
}

void Game::handle_percepts(bool b, int x, int y){
	if(b){
		if(game_board[x][y]->has_event()){
			game_board[x][y]->display_percepts();
		}
	}
}

void Game::display_percepts(){
	int x = p.x;
	int y = p.y;
	string str = "checking" + to_string(x + 1) + ", " + to_string(y);
	handle_percepts((x + 1) < width, x + 1, y);
	str = "checking" + to_string(x) + ", " + to_string(y+1);
	handle_percepts((y + 1) < length, x, y + 1);
	str = "checking" + to_string(x - 1) + ", " + to_string(y);
	handle_percepts((x - 1) > 0, x - 1, y);
	str = "checking" + to_string(x) + ", " + to_string(y-1);
	handle_percepts((y - 1) > 0, x, y - 1);
	refresh();
}

void clean(){
	clear();
	refresh();
}

//Note: you need to modify this function
void Game::play_game(int w, int l, bool d, bool a){
	reset_game(a, w, l);
	this->debug_view = d;
	char input, arrow_input;
	if(d){
		while (Game::check_win() == false && p.is_alive){
			clean();
			Game::display_game_debug();
			Game::display_percepts();
			input = Game::get_input();
			Game::move(input);
		}
	}
	else{
		while (Game::check_win() == false && p.is_alive){
			clean();
			Game::display_game();
			Game::display_percepts();
			input = Game::get_input();
			Game::move(input);
		}
	}
	clean();
	if(Game::check_win() == true){
		printw("You won!\n");
	}
	else{
		printw("You lost!\n");
	}
	refresh();
}
