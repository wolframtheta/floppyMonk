#ifndef _GAME_HPP
#define _GAME_HPP

class Game {
public:
	
	Game(sf::RenderWindow* window);
	
	void play();	
	

private:
	
	sf::Sprite bg;
	sf::RenderWindow* _myWindow;

};

#endif