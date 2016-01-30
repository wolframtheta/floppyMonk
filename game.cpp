#include "utils.hpp"

Game::Game(sf::RenderWindow* window): _myWindow(window){
	
	
	
	//bg.setTextureRect(a,b,c,d); falta posar les dimensions del rectangle aka REKT!!

}

void Game::play(){
	
        sf::Texture bgT;
	if (!bgT.loadFromFile(file_bg)) std::cout << "Error loading spriteSheet" << std::endl;
        bg.setTexture(bgT);
        
	Monjo monjo;
        sf::Sprite player;
        sf::Texture monjoT;
        if (!monjoT.loadFromFile(file_monjo)) std::cout << "Failed to load monjo" << std::endl;
        player.setTexture(monjoT);
	
        
        listNota musica;
        //frequencia entre notes
	float tempo = musica.getTempo();
        sf::Sprite spriteNota;
        sf::Texture notaT;
        if (!notaT.loadFromFile(file_tile)) std::cout << "Failed to load nota" << std::endl;
        spriteNota.setTexture(notaT);
        
	//creem el rellotge del joc
	sf::Clock clock;
	sf::Time time = sf::seconds(0);
	bool pressQ = true, pressW = true, pressE = true, pressR = true;
        bool exitLoop = false;
	
	while(monjo.getLvlConc() > 0 and not exitLoop){ //Player alive
		
                sf::Event event;
                while (_myWindow->pollEvent(event)){
                    if (event.type == sf::Event::Closed) exitLoop = true;
                    if (event.type == sf::Event::KeyPressed){
                        if (event.key.code == sf::Keyboard::Escape){
                            exitLoop = true;
                        }
                    }    
                }
            
            
		_myWindow->clear();
		_myWindow->draw(bg);
		
		
		if  (clock.getElapsedTime().asSeconds() >= tempo) {
			time = clock.restart();
			musica.newNota();
		//}
		
		monjo.update();
                player.setPosition(monjo.getPos());
                _myWindow->draw(player);
		
		bool encert = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) and pressQ){
			encert = musica.encertaNota(1);
			pressQ = false;
		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) pressQ = true;
		
		//if (not encert) jugador.downLvlConc(false);
		//else monjo.upLvlConc();
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and pressW){
			encert = musica.encertaNota(2);
			pressW = false;
		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::W)) pressW = true;
				
		//if (not encert) jugador.downLvlConc(false);
		//else monjo.upLvlConc();
		
		   
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) and pressE){
			encert = musica.encertaNota(3);
			pressE = false;
		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::E)) pressE = true;
		
		//if (not encert) jugador.downLvlConc(false);
		//else monjo.upLvlConc();
				   
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) and pressR){
			encert = musica.encertaNota(4);
			pressR = false;
		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::R)) pressR = true;
		

		//if (not encert) jugador.downLvlConc(false);
		//else monjo.upLvlConc();
		
		bool notaPerduda = false;
		notaPerduda = musica.update();
		if (notaPerduda) monjo.downLvlConc(true);
		std::list<Nota>::iterator it = musica.begin();
		while (it != musica.end()){
                    spriteNota.setPosition((*it).getPosition);
                    _myWindow->draw(spriteNota);
                    it++;
                }
		
		_myWindow->display();
		
	}
	
	if (not exitLoop) { //Player dead
            
            //Game over blah blah blah
        }
	
	
}