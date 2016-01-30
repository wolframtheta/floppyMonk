#include "utils.hpp"

Game::Game(sf::RenderWindow* window):_mywindow(window){
	
	bg.setTexture(spriteSheet);
	//bg.setTextureRect(a,b,c,d); falta posar les dimensions del rectangle aka REKT!!

}

void Game::nextMove(){
	
}

void Game::play(){
	
	listNota musica;
		//frequencia entre notes
	float tempo = musica.getTempo();
	
	Monjo jugador;
	
	//creem el rellotge del joc
	sf::Clock clock;
	sf::Time time = sf::seconds(0);
	
	while(jugador.getLvlCon() != 0){
		if  (clock.getElapsedTime().asSeconds() == tempo) {
			time = clock.restart();
			nextMove();
		}
		
	}
	
}