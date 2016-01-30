floppyMonk: main.o menu.o game.o monjo.o listNota.o nota.o
	g++ main.o menu.o game.o monjo.o listNota.o nota.o -o floppyMonk -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
	
main.o: main.cpp
	g++ -c main.cpp 

menu.o: menu.cpp
	g++ -c menu.cpp
	
game.o: game.cpp
	g++ -c game.cpp

monjo.o: monjo.cpp
	g++ -c monjo.cpp

listNota.o: listNota.cpp
	g++ -c listNota.cpp
	
nota.o: nota.cpp
	g++ -c nota.cpp
	
clean:
	rm *.o
	rm floppyMonk