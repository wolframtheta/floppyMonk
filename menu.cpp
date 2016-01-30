#include "utils.hpp"

void Menu::run(){
    
    sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), APP_NAME);
    window.setFramerateLimit(60);
    //sf::Texture spriteSheet;
    //if (!spriteSheet.loadFromFile("./images/spriteSheet.jpg")) std::cout << "Error loading spriteSheet" << std::endl;
    
    sf::RectangleShape bg;
    //bg.setTexture(spriteSheet);
    //bg.setTextureRect(posx,posy,midax,miday)
    bg.setFillColor(sf::Color(0,0,0));
    
    
    sf::RectangleShape play;
    play.setFillColor(sf::Color(255,255,255));
    play.setSize(sf::Vector2f(150,50));
    play.setPosition(20,20);
    sf::IntRect Rplay(20,20,150,50);
    
    sf::RectangleShape credits;
    credits.setFillColor(sf::Color(255,255,255));
    credits.setSize(sf::Vector2f(150,50));
    credits.setPosition(20,90);
    sf::IntRect Rcred(20,90,150,50);
    
    
    sf::RectangleShape exit;
    exit.setFillColor(sf::Color(255,255,255));
    exit.setSize(sf::Vector2f(150,50));
    exit.setPosition(20,160);
    sf::IntRect Rexit(20,160,150,50);
    
    
    

    
    while (window.isOpen()){
        window.clear();
        
        
        sf::Event event;
        while (window.pollEvent(event)){
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
                    sf::Text creditText("GameJam Barcelona 2016",font,30);
                    creditText.setColor(sf::Color(255,255,255));
                    for (int i = W_HEIGHT;i>0;i--){
                        window.clear();
                        window.draw(bg);
                        
                        creditText.setPosition((float)W_WIDTH/5,(float)i);
                        window.draw(creditText);
                        window.display();
                        
                    }
                    
                    play.setPosition(20,20);
                    credits.setPosition(20,90);
                    exit.setPosition(20,160);
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