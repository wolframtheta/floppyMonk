#include "utils.hpp"

Game::Game(sf::RenderWindow* window): _myWindow(window){
	
	
	sf::Texture bgT;
	if (!bgT.loadFromFile(file_bg)) std::cout << "Error loading spriteSheet" << std::endl;
    bg.setTexture(bgT);
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
	
	while(jugador.getLvlConc() > 0){
		
		if  (clock.getElapsedTime().asSeconds() >= tempo) {
			time = clock.restart();
			musica.newNota();
		}
		
		jugador.update(_myWindow);
		
		
		bool encert = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) and pressQ){
			encert = musica.encertaNota(1);
			pressQ = false;
		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) pressQ = true;
		
		if (not encert) jugador.downLvlConc(false);
		else jugador.upLvlConc();
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and pressW){
			encert = musica.encertaNota(2);
			pressW = false;
		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::W)) pressW = true;
				
		if (not encert) jugador.downLvlConc(false);
		else jugador.upLvlConc();
		
		   
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) and pressE){
			encert = musica.encertaNota(3);
			pressE = false;
		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::E)) pressE = true;
		
		if (not encert) jugador.downLvlConc(false);
		else jugador.upLvlConc();
				   
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) and pressR){
			encert = musica.encertaNota(4);
			pressR = false;
		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::R)) pressR = true;
		
		if (not encert) jugador.downLvlConc(false);
		else jugador.upLvlConc();
		
		bool notaPerduda = false;
		notaPerduda = musica.update();
		if (notaPerduda) jugador.downLvlConc(true);
	}
	
}