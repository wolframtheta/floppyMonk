#include "utils.hpp"

void Menu::run(){
    
    sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), APP_NAME/*, sf::Style::Fullscreen*/);
    window.setFramerateLimit(60);
    sf::Texture bgT;
    if (!bgT.loadFromFile(file_bg)) std::cout << "Error loading spriteSheet" << std::endl;
    
    sf::RectangleShape bg;
    //bg.setTextureRect(posx,posy,midax,miday)
    bg.setTexture(&bgT);
    bg.setSize(sf::Vector2f(W_WIDTH, W_HEIGHT));
    bg.setPosition(0,0);
    
    sf::Texture bgPlay;
    if (!bgPlay.loadFromFile(file_play)) std::cout << "Error loading spriteSheet" << std::endl;
    
    sf::RectangleShape play;
    play.setTexture(&bgPlay);
    play.setSize(sf::Vector2f(W_WIDTH/3,W_HEIGHT/7));
    play.setPosition(W_WIDTH/2-W_WIDTH/3/2,W_HEIGHT*1/5-W_HEIGHT/7/2);
    sf::IntRect Rplay(W_WIDTH/2-W_WIDTH/3/2,W_HEIGHT*1/5-W_HEIGHT/7/2,W_WIDTH/3,W_HEIGHT/7);
    

    sf::Texture bgCredits;
    if (!bgCredits.loadFromFile(file_credits)) std::cout << "Error loading spriteSheet" << std::endl;
    
    sf::RectangleShape credits;
    credits.setTexture(&bgCredits);
    credits.setSize(sf::Vector2f(W_WIDTH/3,W_HEIGHT/7));
    credits.setPosition(W_WIDTH/2-W_WIDTH/3/2,W_HEIGHT*2/5-W_HEIGHT/7/2);
    sf::IntRect Rcred(W_WIDTH/2-W_WIDTH/3/2,W_HEIGHT*2/5-W_HEIGHT/7/2,W_WIDTH/3,W_HEIGHT/7);
   

   sf::Texture bgExit;
    if (!bgExit.loadFromFile(file_exit)) std::cout << "Error loading spriteSheet" << std::endl;
    
    
    
    sf::RectangleShape exit;
    exit.setTexture(&bgExit);
    exit.setSize(sf::Vector2f(W_WIDTH/3,W_HEIGHT/7));
    exit.setPosition(W_WIDTH/2-W_WIDTH/3/2,W_HEIGHT*3/5-W_HEIGHT/7/2);
    sf::IntRect Rexit(W_WIDTH/2-W_WIDTH/3/2,W_HEIGHT*3/5-W_HEIGHT/7/2,W_WIDTH/3,W_HEIGHT/7);
    sf::SoundBuffer buffer;
        sf::Sound backgroundS;
        buffer.loadFromFile("./resources/music/BSong.ogg");
        backgroundS.setBuffer(buffer);
        backgroundS.play();
     
    

    
    while (window.isOpen()){
        window.clear();
        
        
        sf::Event event;
        /*bool fullscreen;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) and sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)) {
            fullscreen = !fullscreen;
            window.create(sf::VideoMode(W_WIDTH, W_HEIGHT), APP_NAME, (fullscreen ? sf::Style::Fullscreen : sf::Style::Resize|sf::Style::Close));
        }*/
        while (window.pollEvent(event)){

            //Exit
            
            //Fullscreen toggle
            

            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Escape){
                    window.close();
                }
            }
           

            
            if (event.type == sf::Event::MouseButtonReleased){
                sf::Vector2i mousepos = sf::Mouse::getPosition(window);
                sf::IntRect cursorAim(mousepos.x-1,mousepos.y-1,2,2);
                if (cursorAim.intersects(Rplay)){
                    std::cout << "Play ok!" << std::endl;
					
                    play.setPosition(-500,-500);
                    credits.setPosition(-500,-500);
                    exit.setPosition(-500,-500);
					
                    Game joc(&window);
                    joc.play();
					
					
                    play.setPosition(W_WIDTH/2-W_WIDTH/3/2,W_HEIGHT*1/5-W_HEIGHT/7/2);
                    credits.setPosition(W_WIDTH/2-W_WIDTH/3/2,W_HEIGHT*2/5-W_HEIGHT/7/2);
                    exit.setPosition(W_WIDTH/2-W_WIDTH/3/2,W_HEIGHT*3/5-W_HEIGHT/7/2);
					
					sf::RectangleShape fadeRct(sf::Vector2f(W_WIDTH,W_HEIGHT));
					
					int i = 255;
					while (i > 0){
						
						window.clear();
						window.draw(bg);
						window.draw(play);
						window.draw(credits);
						window.draw(exit);
						
						fadeRct.setFillColor(sf::Color(0,0,0,i));
						window.draw(fadeRct);
						window.display();
						i-=3;
					}
					
                    //Hide buttons
                    //joc.play()
                    //Show buttons
                }
                else if (cursorAim.intersects(Rcred)){
                    std::cout << "Credits ok!" << std::endl;
                    
                    play.setPosition(-500,-500);
                    credits.setPosition(-500,-500);
                    exit.setPosition(-500,-500);
                    
                    //Roll credits
                    sf::Font font;
                    if (!font.loadFromFile("./resources/RemachineScript_Personal_Use.ttf")) std::cout << "Failed to load font" << std::endl;
                    sf::Text creditText("GameJam Barcelona Dos Mil Setze\n Creado Por: \nXavier --- \n Xavier --- \n Marti --- \n Ruben Cano Diaz",font,100);
                    creditText.setColor(sf::Color(255,255,255));
                    for (int i = W_HEIGHT;i>0;i-=4){
                        
                        
                        
                        window.clear();
                        window.draw(bg);

                        creditText.setPosition((float)350,(float)i);
                        window.draw(creditText);
                        
                        sf::Event event2;
                        while (window.pollEvent(event2)){
                            if (event2.type == sf::Event::Closed) i=-1;
                            if (event2.type == sf::Event::KeyPressed){
                                if (event2.key.code == sf::Keyboard::Escape){
                                    i=-1;
                                }
                            }
                        }
                        window.display();
                        
                    }
                    
                    play.setPosition(W_WIDTH/2-W_WIDTH/3/2,W_HEIGHT*1/5-W_HEIGHT/7/2);
                    credits.setPosition(W_WIDTH/2-W_WIDTH/3/2,W_HEIGHT*2/5-W_HEIGHT/7/2);
                    exit.setPosition(W_WIDTH/2-W_WIDTH/3/2,W_HEIGHT*3/5-W_HEIGHT/7/2);
                    //Display buttons
                }
                else if (cursorAim.intersects(Rexit)){
                    window.close();
                }
            }
            
        }
        
        
        window.draw(bg);
        window.draw(play);
        window.draw(credits);
        window.draw(exit);
        
        
        
        
        window.display();
    }
    
}