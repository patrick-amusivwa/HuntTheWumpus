Hunt: main.cpp event.o wumpus.o bat.o pit.o room.o gold.o board.o
	g++ main.cpp event.o wumpus.o bat.o pit.o room.o gold.o board.o -o Hunt

event.o: event.cpp event.hpp
	g++ event.cpp -c
wumpus.o: wumpus.cpp wumpus.hpp
	g++ wumpus.cpp -c
bat.o: bat.cpp bat.hpp
	g++ bat.cpp -c
pit.o: pit.cpp pit.hpp
	g++ pit.cpp -c 
room.o: room.cpp room.hpp
	g++ room.cpp -c
gold.o: gold.cpp gold.hpp
	g++ gold.cpp -c
board.o: board.cpp board.hpp
	g++ board.cpp -c
clean:
	rm -f *.o Hunt
