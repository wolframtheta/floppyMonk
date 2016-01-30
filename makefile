floppyMonk: main.o menu.o game.o monjo.o listNota.o nota.o
	g++ main.o menu.o game.o monjo.o listNota.o nota.o -o floppyMonk -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
	
main.o: main.cpp
	g++ -c main.cpp -std=c++14

menu.o: menu.cpp
	g++ -c menu.cpp -std=c++14
	
game.o: game.cpp
	g++ -c game.cpp -std=c++14

monjo.o: monjo.cpp
	g++ -c monjo.cpp -std=c++14

listNota.o: listNota.cpp
	g++ -c listNota.cpp -std=c++14
	
nota.o: nota.cpp
	g++ -c nota.cpp -std=c++14
	
clean:
	rm *.o
	rm floppyMonk