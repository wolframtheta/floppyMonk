floppyMonk: main.o menu.o
	g++ main.o menu.o -o floppyMonk -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
	
main.o: main.cpp
	g++ -c main.cpp 

menu.o: menu.cpp
	g++ -c menu.cpp
	
clean:
	rm *.o
	rm floppyMonk