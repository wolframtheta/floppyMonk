#include "utils.hpp"


void initView(sf::View* view, sf::RenderWindow* _window, sf::Vector2i windowSize) {
    int windowX = _window->getSize().x, windowY = _window->getSize().y;

    float xr = windowX / float(windowSize.x);
    float yr = windowY / float(windowSize.y);

    float aux;
    if (xr < yr) aux = 1/yr;
    else aux = 1/xr;

    xr *= aux;
    yr *= aux;
    sf::Vector2f min,max;

    min.x = (1.f - yr) / 2.f;
    min.y = (1.f - xr) / 2.f;
    max.x = 1.f - min.x*2;
    max.y = 1.f - min.y*2;

    view->reset(sf::FloatRect(0,0,windowSize.x,windowSize.y));
    view->setViewport(sf::FloatRect(min.x,min.y,max.x,max.y));
}




void Menu::run(){
    
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), APP_NAME/*, sf::Style::Fullscreen*/);
        window.setFramerateLimit(60);

    sf::View view;
        view = window.getDefaultView();
        initView(&view,&window,sf::Vector2i(W_WIDTH,W_HEIGHT));

        window.setView(view);



    sf::Texture bgT;
    if (!bgT.loadFromFile(file_bg)) std::cout << "Error loading spriteSheet" << std::endl;
    
    sf::RectangleShape bg;
    //bg.setTextureRect(posx,posy,midax,miday)
        bg.setTexture(&bgT);
        bg.setSize(sf::Vector2f(W_WIDTH, W_HEIGHT));
        bg.setPosition(0,0);
    
    sf::Texture bgPlay;
        if (!bgPlay.loadFromFile(file_play)) std::cout << "Error loading Play button" << std::endl;
    
    sf::RectangleShape play;
        play.setTexture(&bgPlay);
        play.setSize(sf::Vector2f(640,155));
        play.setPosition(W_WIDTH/2-320,W_HEIGHT*1/7-155/2);
    sf::IntRect Rplay(W_WIDTH/2-320,W_HEIGHT*1/7-155/2,640,155);
    

    sf::Texture bgCredits;
        if (!bgCredits.loadFromFile(file_credits)) std::cout << "Error loading Credits button" << std::endl;
    
    sf::RectangleShape credits;
        credits.setTexture(&bgCredits);
        credits.setSize(sf::Vector2f(640,155));
        credits.setPosition(W_WIDTH/2-320,W_HEIGHT*3/7-155/2);
    sf::IntRect Rcred(W_WIDTH/2-320,W_HEIGHT*3/7-155/2,640,155);
   

    sf::Texture bgExit;
        if (!bgExit.loadFromFile(file_exit)) std::cout << "Error loading Exit button" << std::endl;
    
    sf::RectangleShape exit;
        exit.setTexture(&bgExit);
        exit.setSize(sf::Vector2f(640,155));
        exit.setPosition(W_WIDTH/2-320,W_HEIGHT*5/7-155/2);
    sf::IntRect Rexit(W_WIDTH/2-320,W_HEIGHT*5/7-155/2,640,155);
    
    
    
    sf::SoundBuffer buffer;
        sf::Sound backgroundS;
        buffer.loadFromFile("./resources/music/BSong.ogg");
        backgroundS.setBuffer(buffer);
        backgroundS.play();
            

    while (window.isOpen()){
        window.clear();
        

        sf::Event event;
        
        window.draw(bg);
        window.draw(play);
        window.draw(credits);
        window.draw(exit);
        
        //std::cout << "P " << credits.getPosition().x << " " << credits.getPosition().y << " " << Rcred.left << " " << Rcred.top << std::endl;
        
        
        window.display();
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
                
                sf::Vector2f worldPos = window.mapPixelToCoords(mousepos);

                sf::IntRect cursorAim(worldPos.x-1,worldPos.y-1,2,2);
                
                std::cout << "Mouse " << mousepos.x << " " << mousepos.y << " " << worldPos.x << " " << worldPos.y << std::endl;
                
                if (cursorAim.intersects(Rplay)){
                    std::cout << "Play ok!" << std::endl;
					
                    play.setPosition(-500,-500);
                    credits.setPosition(-500,-500);
                    exit.setPosition(-500,-500);
					
                    Game joc(&window);
                    joc.play();
					
					
                    play.setPosition(W_WIDTH/2-320,W_HEIGHT*1/7-155/2);
                    credits.setPosition(W_WIDTH/2-320,W_HEIGHT*3/7-155/2);
                    exit.setPosition(W_WIDTH/2-320,W_HEIGHT*5/7-155/2);
					
					sf::RectangleShape fadeRct(sf::Vector2f(W_WIDTH,W_HEIGHT));
					
					int i = 255;
					while (i > 0){
						
						window.clear();
						window.draw(bg);
						window.draw(play);
						window.draw(credits);
                        //window.draw(title);
						window.draw(exit);
						
						fadeRct.setFillColor(sf::Color(0,0,0,i));
						window.draw(fadeRct);
						window.display();
						i-=5;
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
                    sf::Text creditText("GameJam Barcelona\n Creado Por: \n          Xavier Marques \n          Xavier Penalosa \n          Marti Homes \n          Ruben Cano Diaz",font,100);
                    creditText.setColor(sf::Color(255,255,255));
                    for (int i = W_HEIGHT;i>-W_HEIGHT/2;i-=7){
                        
                        
                        
                        window.clear();
                        window.draw(bg);

                        creditText.setPosition((float)350,(float)i);
                        window.draw(creditText);
                        
                        sf::Event event2;
                        while (window.pollEvent(event2)){
                            if (event2.type == sf::Event::Closed) i=-3000;
                            if (event2.type == sf::Event::KeyPressed){
                                if (event2.key.code == sf::Keyboard::Escape){
                                    i=-3000;
                                }
                            }
                        }
                        window.display();
                        
                    }
                    
                    play.setPosition(W_WIDTH/2-320,W_HEIGHT*1/7-155/2);
                    credits.setPosition(W_WIDTH/2-320,W_HEIGHT*3/7-155/2);
                    exit.setPosition(W_WIDTH/2-320,W_HEIGHT*5/7-155/2);
                    //Display buttons
                }
                else if (cursorAim.intersects(Rexit)){
                    window.close();
                }
                /*else if (cursorAim.intersects(Rhtp)) {
                    cout << "how to play" << endl;

                    play.setPosition(-500,-500);
                    credits.setPosition(-500,-500);
                    exit.setPosition(-500,-500);

                    window.clear();

                    sf::Texture bgHTP;
                    if (!bgHTP.loadFromFile(file_bgHTP)) std::cout << "Error loading spriteSheet" << std::endl;
                    sf::Sprite bgS;
                    bgS.setTexture(bgHTP);

                    window.draw(bgS);
                    window.display();
                    while(1);
                }*/
            }
            
        }


    }
    
}
