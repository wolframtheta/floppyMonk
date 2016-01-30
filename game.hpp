#ifndef _GAME_HPP
#define _GAME_HPP

class Game {
public:
	
	Game(sf::RenderWindow* window);
	
	//crea nota, afageix a la llista i avança el ""temps"" del joc
	void nextMove();
	
	void play();	
	

private:
	
	sf::Sprite bg;
	sf::RenderWindow* _myWindow;

};

#endif