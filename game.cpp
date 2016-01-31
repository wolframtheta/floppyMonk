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


        sf::Texture monjoT;
            if (!monjoT.loadFromFile(file_monjo)) std::cout << "Failed to load monjo" << std::endl;
        sf::Sprite player;
            player.setTexture(monjoT);
	
            
            
        Monjo monjo;
        listNota musica(false);
        listNota musica2(true);
        //frequencia entre notes

        sf::Texture notaT;
            if (!notaT.loadFromFile(file_tile)) std::cout << "Failed to load nota" << std::endl;
        sf::Sprite spriteNota;
            spriteNota.setTexture(notaT);
        
	//creem el rellotge del joc
	sf::Clock clock;
        sf::Clock clock2;
	sf::Time time = sf::seconds(0);
        sf::Time time2 = sf::seconds(0);
        
        //Control de les tecles que es poden prémer
	bool pressQ = true, pressW = true, pressE = true, pressR = true;
        bool pressU = true, pressI = true, pressO = true, pressP = true;
        
        //Control dels carrils per els quals poden apareixer notes
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

                
        sf::Sprite hBRectangle;                 //Draw zone QWER
            hBRectangle.setTexture(notaT);
            hBRectangle.setTextureRect(sf::IntRect(0,0,420,120));
            hBRectangle.setPosition(posRectangle);

        sf::Sprite hBRectangle2;                //Draw zone UIOP
            hBRectangle2.setTexture(notaT);
            hBRectangle2.setTextureRect(sf::IntRect(0,0,420,120));
            hBRectangle2.setPosition(posRectangle2);
 
        sf::Sprite keyHint1;
        	keyHint1.setTexture(notaT);
        	keyHint1.setPosition(posRectangle.x,posRectangle.y+20);
        sf::Sprite keyHint2;
        	keyHint2.setTexture(notaT);
        	keyHint2.setPosition(posRectangle2.x,posRectangle2.y+20);

        sf::Texture glow;
            if (!glow.loadFromFile(file_glow)) std::cout << "Error loading glow" << std::endl;
        
        sf::Sprite comboGlow;
            comboGlow.setTexture(glow);
            

	while(monjo.getHp() > 0 and not exitLoop){ //Player alive

            if (acertadas >= 10) notes_disponibles = 4;
            if (acertadas >= 30) notes_disponibles = 8;
            
            if (notes_disponibles>=2){ //QW
                canQ = true; canW = true;
                if (notes_disponibles>=4){ //QWER
                    canE = true; canR = true;
                    if (notes_disponibles==8){  //QWER UIOP
                        canU = true; canI = true; canO = true; canP = true;
                    }
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

            if (notes_disponibles==2){
            	keyHint1.setTextureRect(sf::IntRect(0,200,210,80));
            	_myWindow->draw(keyHint1);
            }
            else if (notes_disponibles==4){
				keyHint1.setTextureRect(sf::IntRect(0,200,480,80));
				_myWindow->draw(keyHint1);
            }
            else if (notes_disponibles==8){
            	keyHint1.setTextureRect(sf::IntRect(0,200,480,80));
            	keyHint2.setTextureRect(sf::IntRect(0,280,480,80));
            	_myWindow->draw(keyHint1);
            	_myWindow->draw(keyHint2);
            }
            
            if (notes_disponibles>0){ //Key presses
                int oldFalladas = falladas;
                bool encert = false;
                
                if  (clock.getElapsedTime().asSeconds() >= musica.getTempo()) {
                    time = clock.restart();
                    musica.newNota(notes_disponibles);
                }
                if  (clock2.getElapsedTime().asSeconds() >= musica2.getTempo()) {
                    time2 = clock2.restart();
                    musica2.newNota(notes_disponibles);
                }
                
                //Per a cada nota disponible, comprovar si s'encerta o es falla i canviar concentració
                if (canQ){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) and pressQ ){
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

                int spx;
                if (falladas > oldFalladas) spx = 1280;
                else {
                    if (monjo.getLvlConc()<62.5) spx = 0;
                    else if (monjo.getLvlConc()<125) spx = 320;
                    else if (monjo.getLvlConc()<187.5) spx = 640;
                    else spx = 960;
                    
                }
                player.setPosition(monjo.getPos());
                player.setTextureRect(sf::IntRect(spx,0,320,320));
                _myWindow->draw(player);
            }

            std::list<Nota>::iterator it = musica.listNotes.begin();
            std::list<Nota>::iterator it2 = musica2.listNotes.begin();
            
            while (it != musica.listNotes.end()){ //Draw notes QWER
                spriteNota.setTextureRect(sf::IntRect(((*it).getType()-1)*80,120,80,80));
                spriteNota.setPosition(sf::Vector2f((*it).getPos().x + ((*it).getType()-1)*100, (*it).getPos().y));
                _myWindow->draw(spriteNota);
                it++;
            }
            while (it2 != musica2.listNotes.end()){ //Draw notes UIOP
                spriteNota.setTextureRect(sf::IntRect(((*it2).getType()-1)*80,120,80,80));
                spriteNota.setPosition(sf::Vector2f((*it2).getPos().x + ((*it2).getType()-1)*100, (*it2).getPos().y));
                _myWindow->draw(spriteNota);
                it2++;
            }
            
            _myWindow->draw(hBRectangle);
            _myWindow->draw(hBRectangle2);
            comboGlow.setTextureRect(sf::IntRect(0,140*multiplicador-1,440,140));
            comboGlow.setPosition(posRectangle.x-10,posRectangle.y-10);
            _myWindow->draw(comboGlow);
            comboGlow.setPosition(posRectangle2.x-10,posRectangle2.y-10);
            _myWindow->draw(comboGlow);
            
            
                
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

            hp2.setSize(sf::Vector2f(maxim(0,((float)monjo.getHp()/100.0f)*W_WIDTH/3),20));

            _myWindow->draw(hp1);
            _myWindow->draw(hp2);
            _myWindow->display();
		
            musica.setTempo(vel[((monjo.getLvlConc()-1)/25)%10]);
            musica2.setTempo(vel[((monjo.getLvlConc()-1)/25)%10]);

            ////puntuacuiones
            if(racha>max_combo) max_combo=racha;

            if(racha<=5 and racha>1) multiplicador = 2;
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