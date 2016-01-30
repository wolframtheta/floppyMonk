#include "utils.hpp"

void Menu::run(){
    
    sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), APP_NAME);
    
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
                    //Hide buttons
                    //Roll the credits
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