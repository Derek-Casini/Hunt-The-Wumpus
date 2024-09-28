CC=g++ -std=c++11 -g
EXE_FILE=asm4
FLAGS = -c -Wall
LFLAGS = -lncurses

all: $(EXE_FILE)

$(EXE_FILE): bats.o escape.o event.o game.o gold.o armor.o player.o room.o passage.o stalactites.o wumpus.o main.o
	$(CC) bats.o escape.o event.o game.o gold.o armor.o player.o room.o passage.o stalactites.o wumpus.o main.o -o $(EXE_FILE) $(LFLAGS)

bats.o: bats.h bats.cpp
	$(CC) $(FLAGS) bats.cpp

escape.o: escape.h escape.cpp
	$(CC) $(FLAGS) escape.cpp
	
passage.o: passage.h passage.cpp
	$(CC) $(FLAGS) passage.cpp

event.o: event.h event.cpp
	$(CC) $(FLAGS) event.cpp

game.o: game.h game.cpp
	$(CC) $(FLAGS) game.cpp

gold.o: gold.h gold.cpp
	$(CC) $(FLAGS) gold.cpp

armor.o: armor.h armor.cpp
	$(CC) $(FLAGS) armor.cpp

player.o: player.h player.cpp
	$(CC) $(FLAGS) player.cpp

room.o: room.h room.cpp
	$(CC) $(FLAGS) room.cpp

stalactites.o: stalactites.h stalactites.cpp
	$(CC) $(FLAGS) stalactites.cpp

wumpus.o: wumpus.h wumpus.cpp
	$(CC) $(FLAGS) wumpus.cpp

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

clean:
	rm -f *.o $(EXE_FILE)