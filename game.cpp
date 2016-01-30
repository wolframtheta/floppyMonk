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
                int notes_disponibles = 2;
		int mana = 0;
		sf::Clock GameTime; // starts the clock




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
        
        //Control de les tecles que es poden prémer
	bool pressQ = true, pressW = true, pressE = false, pressR = false;
        bool pressU = false, pressI = false, pressO = false, pressP = false;
        
        bool canQ, canW, canE, canR, canU, canI, canO, canP;
        
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

            if (notes_disponibles>=4){ //QWER
                canE = true; canR = true;
                if (notes_disponibles==8){  //QWER UIOP
                    canU = true; canI = true; canO = true; canP = true;
                }
            }


            
            
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

            
            if (notes_disponibles>0){ //Key presses
                int oldFalladas = falladas;
                bool encert = false;
                
                if  (clock.getElapsedTime().asSeconds() >= musica.getTempo()) {
                    time = clock.restart();
                    musica.newNota();
                }
                if  (clock.getElapsedTime().asSeconds() >= musica2.getTempo()) {
                    time = clock.restart();
                    musica2.newNota();
                }
                
                //Per a cada nota disponible, comprovar si s'encerta o es falla i canviar concentració
                if (canQ){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) and pressQ ){                   //Q
                        soundQ.play();
                        encert = musica.encertaNota(1);
                        pressQ = false;
                        if (not encert) {
                            monjo.downLvlConc(false);
                            racha=0;
                            falladas++;
                            multiplicador=1;
                                //wrongTile();
                        }
                        else {
                            monjo.upLvlConc();
                            racha++;
                            acertadas++;
                            mana= mana + 2*multiplicador; //2 puntos sin multiplicador.
                        }
                    }
                    else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) pressQ = true;
                }

                if (canW){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and pressW){
                            soundW.play();
                            encert = musica.encertaNota(2);
                            pressW = false;
                            if (not encert){
                                    monjo.downLvlConc(false);
                                    racha=0;
                                    falladas++;
                                    multiplicador=1;

                            }
                            else {
                                    monjo.upLvlConc();
                                    racha++;
                                    acertadas++;
                                    mana= mana + 2*multiplicador; //2 puntos sin multiplicador.

                            }

                    }
                    else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::W)) pressW = true;
                }          
                
                if (canE){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) and pressE){
                            soundE.play();
                            encert = musica.encertaNota(3);
                            pressE = false;
                            if (not encert){
                                    monjo.downLvlConc(false);
                                    racha=0;
                                    falladas++;
                                    multiplicador=1;

                            }
                            else {
                                    monjo.upLvlConc();
                                    racha++;
                                    acertadas++;
                                    mana= mana + 2*multiplicador; //2 puntos sin multiplicador.

                            }

                    }
                    else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::E)) pressE = true;
                }
                
                if (canR){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) and pressR){
                            soundR.play();
                            encert = musica.encertaNota(4);
                            pressR = false;
                            if (not encert) {
                                    monjo.downLvlConc(false);
                                    racha=0;
                                    falladas++;
                                    multiplicador=1;

                            }
                            else {
                                    monjo.upLvlConc();
                                    racha++;
                                    acertadas++;
                                    mana= mana + 2*multiplicador; //2 puntos sin multiplicador.

                            }

                    }
                    else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::R)) pressR = true;
                }
                
                if (canU){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) and pressU){
                        soundQ.play();
                        encert = musica2.encertaNota(1);
                        pressQ = false;
                        if (not encert){
                                monjo.downLvlConc(false);
                                racha=0;
                                falladas++;
                                multiplicador=1;
                        }
                        else {
                            monjo.upLvlConc();
                            racha++;
                            acertadas++;
                            mana= mana + 2*multiplicador; //2 puntos sin multiplicador.
                        }
                    }
                    else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::U)) pressU = true;
                }
                
                if (canI){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) and pressI){
                        soundW.play();
                        encert = musica2.encertaNota(2);
                        pressW = false;
                        if (not encert){
                            monjo.downLvlConc(false);
                            racha=0;
                            falladas++;
                            multiplicador=1;
                        }
                        else {
                            monjo.upLvlConc();
                            racha++;
                            acertadas++;
                            mana= mana + 2*multiplicador; //2 puntos sin multiplicador.
                        }
                    }
                    else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::I)) pressI = true;
                }
                            
                if (canO){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) and pressO){
                        soundE.play();
                        encert = musica2.encertaNota(3);
                        pressE = false;
                        if (not encert){
                            monjo.downLvlConc(false);
                            racha=0;
                            falladas++;
                            multiplicador=1;
                        }
                        else {
                            monjo.upLvlConc();
                            racha++;
                            acertadas++;
                            mana= mana + 2*multiplicador; //2 puntos sin multiplicador
                        }
                    }
                    else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::O)) pressO = true;
                }
                
                if (canP){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) and pressP){
                        soundR.play();
                        encert = musica2.encertaNota(4);
                        pressR = false;
                        if (not encert){
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
                    else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::P)) pressP = true;
                }

                bool notaPerduda = false;
                notaPerduda = musica.update() and musica2.update();
                if (notaPerduda) {
                        monjo.downLvlConc(true);
                        racha = 0;
                        falladas++;
                        multiplicador = 1;
                }
                std::list<Nota>::iterator it = musica.listNotes.begin();

                if (falladas > oldFalladas) spx = 1280;
                
            }

            player.setTextureRect(sf::IntRect(spx,0,320,320));
            _myWindow->draw(player);
=======
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

       sf::Sprite hBRectangle;
		hBRectangle.setTexture(notaT);
		hBRectangle.setTextureRect(sf::IntRect(0,0,420,120));
		hBRectangle.setPosition(posRectangle);

       	sf::Text numberMultiplier(to_string(multiplicador), font, 70);
       	numberMultiplier.setPosition(1850, 1000);
       	switch (multiplicador) {
       		case 2:
       			numberMultiplier.setColor(sf::Color(0,0,204));
       			hBRectangle.setColor(sf::Color(0,0,204));
       			break;
       		case 3:
				numberMultiplier.setColor(sf::Color(128,255,0));
       			hBRectangle.setColor(sf::Color(128,255,0));
				break;
       		case 4:
   				numberMultiplier.setColor(sf::Color(0,51,0));
       			hBRectangle.setColor(sf::Color(0,51,0));
   				break;
       		case 5:
       			numberMultiplier.setColor(sf::Color(204,0,204));
       			hBRectangle.setColor(sf::Color(204,0,204));
       			break;
       		case 6:	
       			numberMultiplier.setColor(sf::Color(255,0,0));
       			hBRectangle.setColor(sf::Color(255,0,0));
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