//#include "utils.hpp"

#include "menu.hpp"
#include <SFML/Graphics.hpp>

void Menu::run(){
    
    sf::RenderWindow window(sf::VideoMode(400, 600), "Floppy Monk");
    
    //sf::Texture spriteSheet;
    //if (!spriteSheet.loadFromFile("./images/spriteSheet.jpg")) std::cout << "Error loading spriteSheet" << std::endl;
    
    sf::RectangleShape bg;
    //bg.setTexture(spriteSheet);
    //bg.setTextureRect(posx,posy,midax,miday)
    bg.setFillColor(sf::Color(0,0,0));
    
    
    
    sf::RectangleShape play;
    play.setFillColor(sf::Color(255,255,255));
    play.setSize(sf::Vector2f(100,50));
    play.setPosition(20,20);
    
    
    sf::RectangleShape credits;
    credits.setFillColor(sf::Color(255,255,255));
    credits.setSize(sf::Vector2f(100,50));
    credits.setPosition(20,90);
    
    
    sf::RectangleShape exit;
    exit.setFillColor(sf::Color(255,255,255));
    exit.setSize(sf::Vector2f(100,50));
    exit.setPosition(20,160);
    
    sf::RectangleShape cursorAim;
    cursorAim.setSize(sf::Vector2f(2,2));
    cursorAim.setOrigin(1,1);
    
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
                cursorAim.setPosition(sf::Mouse::getPosition(window));
                if (cursorAim.intersects(play)){
                    std::cout << "Play ok!" << std::endl;
                    //Hide buttons
                    //joc.play()
                    //Show buttons
                }
                else if (cursorAim.instersects(credits)){
                    std::cout << "Credits ok!" << std::endl;
                    //Hide buttons
                    //Roll the credits
                    //Display buttons
                }
                else if (cursorAim.intersects(exit)){
                    window.close;
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