#include "utils.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>
Game::Game(sf::RenderWindow* window): _myWindow(window){
	
	
	
	//bg.setTextureRect(a,b,c,d); falta posar les dimensions del rectangle aka REKT!!

}

void Game::play(){
        sf::Texture bgT;
	if (!bgT.loadFromFile(file_bg)) std::cout << "Error loading spriteSheet" << std::endl;
        bg.setTexture(bgT);
        

        sf::RectangleShape hp1;
        hp1.setFillColor(sf::Color(171,0,0));
    	hp1.setSize(sf::Vector2f(W_WIDTH/3,40));
    	hp1.setPosition(200,30);
        sf::RectangleShape hp2;
        hp2.setFillColor(sf::Color(255,0,0));
    	hp2.setSize(sf::Vector2f(W_WIDTH/3,40));
    	hp2.setPosition(200,30);
    	_myWindow->draw(hp1);
    	_myWindow->draw(hp2);


    	//texto score


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
	

    	sf::SoundBuffer buffer1, buffer2, buffer3, buffer4;
		sf::Sound soundQ;
		buffer1.loadFromFile("./resources/music/1.wav");
		soundQ.setBuffer(buffer1);
		sf::Sound soundW;
		buffer2.loadFromFile("./resources/music/15.wav");
		soundW.setBuffer(buffer2);
		sf::Sound soundE;
		buffer3.loadFromFile("./resources/music/34.wav");
		soundE.setBuffer(buffer3);
		sf::Sound soundR;
		buffer4.loadFromFile("./resources/music/48.wav");
		soundR.setBuffer(buffer4);

		

	while(monjo.getHp() > 0 and not exitLoop){ //Player alive
			
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
			
		}
		
		monjo.update();
                player.setPosition(monjo.getPos());
                _myWindow->draw(player);
		
		bool encert = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) and pressQ ){
			soundQ.play();
			encert = musica.encertaNota(1);
			pressQ = false;
			if (not encert) monjo.downLvlConc(false);
			else monjo.upLvlConc();

		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) pressQ = true;
		
				
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and pressW){
			soundW.play();
			encert = musica.encertaNota(2);
			pressW = false;
			if (not encert) monjo.downLvlConc(false);
		else monjo.upLvlConc();

		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::W)) pressW = true;
				
		   
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) and pressE){
			soundE.play();
			encert = musica.encertaNota(3);
			pressE = false;
			if (not encert) monjo.downLvlConc(false);
			else monjo.upLvlConc();

		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::E)) pressE = true;
						   
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) and pressR){
			soundR.play();
			encert = musica.encertaNota(4);
			pressR = false;
			if (not encert) monjo.downLvlConc(false);
			else monjo.upLvlConc();

		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::R)) pressR = true;
		

		bool notaPerduda = false;
		notaPerduda = musica.update();
		if (notaPerduda) monjo.downLvlConc(true);
		std::list<Nota>::iterator it = musica.listNotes.begin();

		

		while (it != musica.listNotes.end()){
                 



			spriteNota.setTextureRect(sf::IntRect(((*it).getType()-1)*80,120,80,80));

			spriteNota.setPosition(sf::Vector2f((*it).getPos().x + ((*it).getType()-1)*100, (*it).getPos().y));

			
            _myWindow->draw(spriteNota);
            it++;
        }
		monjo.regHp();
		sf::Sprite hBRectangle;
		hBRectangle.setTexture(notaT);
		hBRectangle.setTextureRect(sf::IntRect(0,0,420,120));
		hBRectangle.setPosition(posRectangle);
		_myWindow->draw(hBRectangle);
		hp2.setSize(sf::Vector2f(maxim(0,((float)monjo.getHp()/100.0f)*W_WIDTH/3),40));

		_myWindow->draw(hp1);
		_myWindow->draw(hp2);
		_myWindow->display();
		
		musica.setTempo(vel[(monjo.getLvlConc()-1)/25]);
		std::cout<<musica.getTempo()<<std::endl;
	}


	
	if (not exitLoop) { //Player dead
            
            std::cout<<"DEAD"<<std::endl;
        }
	
	
}