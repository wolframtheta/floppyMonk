#include "utils.hpp"
Game::Game(sf::RenderWindow* window): _myWindow(window){
	
	
	
	//bg.setTextureRect(a,b,c,d); falta posar les dimensions del rectangle aka REKT!!

}

void Game::play(){

		//elo system
		int racha = 0;
		int multiplicador = 1;
		int falladas = 0;
		int max_combo = 0;
		int acertadas = 0;
		int mana = 0;
		sf::Clock GameTime; // starts the clock

		//


        sf::Texture bgT;
	if (!bgT.loadFromFile(file_bg)) std::cout << "Error loading spriteSheet" << std::endl;
        bg.setTexture(bgT);
        

        sf::RectangleShape hp1;
        hp1.setFillColor(sf::Color(171,0,0));
    	hp1.setSize(sf::Vector2f(W_WIDTH/3,20));
    	hp1.setPosition(200,130);
        sf::RectangleShape hp2;
        hp2.setFillColor(sf::Color(255,0,0));
    	hp2.setSize(sf::Vector2f(W_WIDTH/3,20));
    	hp2.setPosition(200,130);
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
		buffer1.loadFromFile("./resources/music/1.ogg");
		soundQ.setBuffer(buffer1);	
		sf::Sound soundW;
		buffer2.loadFromFile("./resources/music/2.ogg");
		soundW.setBuffer(buffer2);
		sf::Sound soundE;
		buffer3.loadFromFile("./resources/music/3.ogg");
		soundE.setBuffer(buffer3);
		sf::Sound soundR;
		buffer4.loadFromFile("./resources/music/4.ogg");
		soundR.setBuffer(buffer4);

		

	while(monjo.getHp() > 0 and not exitLoop){ //Player alive
			
                sf::Event event3;
                while (_myWindow->pollEvent(event3)){
                    if (event3.type == sf::Event::Closed) exitLoop = true;
                    if (event3.type == sf::Event::KeyPressed){
                        if (event3.key.code == sf::Keyboard::Escape){
                            exitLoop = true;
                        }
                    }    
                }
            
		_myWindow->clear();
		_myWindow->draw(bg);
		
		
		if  (clock.getElapsedTime().asSeconds() >= musica.getTempo()) {
			time = clock.restart();
			musica.newNota();
			
		}
				
                player.setPosition(monjo.getPos());

                int spx;
                if (monjo.getLvlConc() < 62.5) spx = 0;
                else if (monjo.getLvlConc() < 125) spx = 320;
                else if (monjo.getLvlConc() < 187.5) spx = 640;
                else spx = 960;


		

		int oldFalladas = falladas;
		bool encert = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) and pressQ ){
			soundQ.play();
			encert = musica.encertaNota(1);
			pressQ = false;
			if (not encert)
			{
				monjo.downLvlConc(false);
				racha=0;
				falladas++;
				multiplicador=1;

			}
			else 
			{
				monjo.upLvlConc();
				racha++;
				acertadas++;
				mana= mana + 2*multiplicador; //2 puntos sin multiplicador.
			}

		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) pressQ = true;
		
				
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and pressW){
			soundW.play();
			encert = musica.encertaNota(2);
			pressW = false;
			if (not encert)
			{
				monjo.downLvlConc(false);
				racha=0;
				falladas++;
				multiplicador=1;

			}
			else 
			{
				monjo.upLvlConc();
				racha++;
				acertadas++;
				mana= mana + 2*multiplicador; //2 puntos sin multiplicador.

			}

		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::W)) pressW = true;
				
		   
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) and pressE){
			soundE.play();
			encert = musica.encertaNota(3);
			pressE = false;
			if (not encert)
			{
				monjo.downLvlConc(false);
				racha=0;
				falladas++;
				multiplicador=1;

			}
			else 
			{
				monjo.upLvlConc();
				racha++;
				acertadas++;
				mana= mana + 2*multiplicador; //2 puntos sin multiplicador.

			}

		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::E)) pressE = true;
						   
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) and pressR){
			soundR.play();
			encert = musica.encertaNota(4);
			pressR = false;
			if (not encert)
			{
				monjo.downLvlConc(false);
				racha=0;
				falladas++;
				multiplicador=1;

			}
			else 
			{
				monjo.upLvlConc();
				racha++;
				acertadas++;
				mana= mana + 2*multiplicador; //2 puntos sin multiplicador.

			}

		}
		else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::R)) pressR = true;
		

		bool notaPerduda = false;
		notaPerduda = musica.update();
		if (notaPerduda) {
			monjo.downLvlConc(true);
			racha = 0;
			falladas++;
			multiplicador = 1;
		}
		std::list<Nota>::iterator it = musica.listNotes.begin();

		if (falladas > oldFalladas) spx = 1280;

        player.setTextureRect(sf::IntRect(spx,0,320,320));
        _myWindow->draw(player);



		while (it != musica.listNotes.end()){
                 



			spriteNota.setTextureRect(sf::IntRect(((*it).getType()-1)*80,120,80,80));

			spriteNota.setPosition(sf::Vector2f((*it).getPos().x + ((*it).getType()-1)*100, (*it).getPos().y));

			
            _myWindow->draw(spriteNota);
            it++;
        }
		sf::Font font;
	    if (!font.loadFromFile("./resources/OpenSans-Regular.ttf")) std::cout << "Failed to load font" << std::endl;
	    sf::Text scoreText("Score: " + to_string(mana),font,50);
	    scoreText.setColor(sf::Color(255,255,255));
	    scoreText.setPosition(250, 60);
        _myWindow->draw(scoreText);

        sf::Text multiplierText("x", font, 50);
       	multiplierText.setColor(sf::Color(105,105,105));
       	multiplierText.setPosition(1820, 1020);
       	_myWindow->draw(multiplierText);

       	sf::Text numberMultiplier(to_string(multiplicador), font, 70);
       	numberMultiplier.setPosition(1850, 1000);
       	switch (multiplicador) {
       		case 2:
       			numberMultiplier.setColor(sf::Color(0,0,204));
       			break;
       		case 3:
				numberMultiplier.setColor(sf::Color(128,255,0));
				break;
       		case 4:
   				numberMultiplier.setColor(sf::Color(0,51,0));
   				break;
       		case 5:
       			numberMultiplier.setColor(sf::Color(204,0,204));
       			break;
       		case 6:	
       			numberMultiplier.setColor(sf::Color(255,0,0));
       			break;
       	}
       	_myWindow->draw(numberMultiplier);


       	sf::Text rachaText(to_string(racha), font, 50);
       	rachaText.setColor(sf::Color(255,255,255));
       	rachaText.setPosition(750, 60);
       	_myWindow->draw(rachaText);

		monjo.regHp();
		sf::Time elapsed_t = GameTime.getElapsedTime();
		monjo.update(elapsed_t.asSeconds());



		sf::Sprite hBRectangle;
		hBRectangle.setTexture(notaT);
		hBRectangle.setTextureRect(sf::IntRect(0,0,420,120));
		hBRectangle.setPosition(posRectangle);
		_myWindow->draw(hBRectangle);
		hp2.setSize(sf::Vector2f(maxim(0,((float)monjo.getHp()/100.0f)*W_WIDTH/3),20));

		_myWindow->draw(hp1);
		_myWindow->draw(hp2);
		_myWindow->display();
		
		musica.setTempo(vel[((monjo.getLvlConc()-1)/25)%10]);


		////puntuacuiones
		if(racha>max_combo) max_combo=racha;

		if(racha<=5) multiplicador = 2;
		else if (racha<=12) multiplicador = 3;
		else if (racha<=17) multiplicador = 4;
		else if (racha<=24) multiplicador = 5;
		else multiplicador = 6;
		///
	}


	
	if (not exitLoop) { //Player dead
	

		
		sf::Time elapsed_t = GameTime.getElapsedTime();
		sf::Font font;
	    if (!font.loadFromFile("./resources/OpenSans-Regular.ttf")) std::cout << "Failed to load font" << std::endl;


		string text = "Score points - " + to_string(mana) 
		+ "\n\nMaximum streak - " + to_string(max_combo) 
		+ "\n\nHits - " + to_string(acertadas) 
		+ "\n\nMisses - " + to_string(falladas)  
		+ "\n\nTime - " + to_string((int) ((elapsed_t.asSeconds() - 0.5)+1))
		+ "seconds\n\n                                               PRESS RETURN TO EXIT";
		sf::Text scoreText(text, font, 20);
		scoreText.setColor(sf::Color(255,255,255));
		scoreText.setPosition(sf::Vector2f(W_WIDTH/2 - 400 + 70,W_HEIGHT/2 - 300 +20));
		_myWindow->draw(scoreText);
		
		
		sf::RectangleShape fadeRct(sf::Vector2f(W_WIDTH,W_HEIGHT));
		int i = 0;
		while (i < 255){
			
			_myWindow->clear();
			_myWindow->draw(bg);
			_myWindow->draw(player);
			
			
			fadeRct.setFillColor(sf::Color(0,0,0,i));
			_myWindow->draw(fadeRct);
			_myWindow->draw(scoreText);
			_myWindow->display();
			i+=5;
		}		
		
		
		
		_myWindow->display();
			while(not sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) ;
           
            std::cout<<"DEAD"<<std::endl;

        }

	
}