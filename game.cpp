#include "utils.hpp"

Game::Game(sf::RenderWindow* window):_mywindow(window){
	
	bg.setTexture(spriteSheet);
	//bg.setTextureRect(a,b,c,d); falta posar les dimensions del rectangle aka REKT!!

}

void Game::play(){
	
	listNota musica;
		//frequencia entre notes
	float tempo = musica.getTempo();
	
	Monjo jugador;
	
	//creem el rellotge del joc
	sf::Clock clock;
	sf::Time time = sf::seconds(0);
	bool pressQ = true, pressW = true, pressE = true, pressR = true;
	
	while(jugador.getLvlCon() > 0){
		if  (clock.getElapsedTime().asSeconds() >= tempo) {
			time = clock.restart();
			musica.newNota();
		}
		
		bool encert = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) and pressQ){
			encert = llistaNotes.encertaNota(1);
			pressQ = false;
		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) pressQ = true;
		
		if (not encert) jugador.downLvlConc(false);
		else jugador.upLvlConc();
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and pressW){
			encert = llistaNotes.encertaNota(2);
			pressW = false
		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::W) pressW = true;
				
		if (not encert) jugador.downLvlConc(false);
		else jugador.upLvlConc();
		
		   
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) and pressE){
			encert = llistaNotes.encertaNota(3);
			pressE = false;
		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::E) pressE = true;
		
		if (not encert) jugador.downLvlConc(false);
		else jugador.upLvlConc();
				   
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) and pressR){
			encert = llistaNotes.encertaNota(4);
			pressR = false;
		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::R) pressR = true;
		
		if (not encert) jugador.downLvlConc(false);
		else jugador.upLvlConc();
		
		bool notaPerduda = false;
		notaPerduda = musica.update();
		if (notaPerduda) jugador.downLvlConc(true);
	}
	
}