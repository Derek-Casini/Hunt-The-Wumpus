#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <ctime>
#include <string>
#include "game.h"

using namespace std;

bool is_number(string num){
	for(char c : num){
		if(!isdigit(c)){
			return false;
		}
	}
	return true;
}

int get_int(string out){
	string input;
	cout << out;
	cin >> input;
	while(!is_number(input)){
		cout << "Invalid input!" << endl;
		cout << out;
		cin >> input;
	}
	system("clear");
	return stoi(input);
}

bool get_debug(){
	cout << "Would you like to run in debug mode? (1 - yes, 0 - no): ";
	int input;
	cin >> input;
	while(input > 1 || input < 0){
		cout << "Invalid input!" << endl;
		cout << "\nWould you like to run in debug mode? (1 - yes, 0 - no): ";
		cin >> input;
	}
	if(input == 1){
		system("clear");
		return true;
	}
	system("clear");
	return false;
}

int get_int_r(string out){
	int i = get_int(out);
	while(i > 1 || i < 0){
		cout << "Invalid input!" << endl;
		i = get_int(out);
	}
	return i;
}

int main()
{
	srand(time(NULL));
	system("clear");
	int wid = get_int("What would you like the width to be: ");
	int len = get_int("What would you like the length to be: ");
	bool debug = get_debug();
	Game g;
	int option = 1;
	bool same = false;
	do{
		g.play_game(wid, len, debug, same);
		endwin();
		option = get_int_r("Would you like to play again? (1 - yes, 0 - no): ");
		if(!g.check_win() && option != 0){
			int r = get_int_r("Would you like to play with the same board? (1 - yes, 0 - no): ");
			if(r == 1){
				same = true;
			}
			else{
				same = false;
				wid = get_int("What would you like the width to be: ");
				len = get_int("What would you like the length to be: ");
				debug = get_debug();
			}
		}
		else if(option != 0){
			wid = get_int("What would you like the width to be: ");
			len = get_int("What would you like the length to be: ");
			debug = get_debug();
		}
		initscr();
		noecho();
	} while(option != 0);
	endwin();
	return 0;
}