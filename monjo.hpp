#ifndef _MONJO_HPP_
#define _MONJO_HPP_

class Monjo {
public:
	
    Monjo();
	
    //sf::Sprite getSprite();
	//void setSprite(sf::Sprite);
	
    void upLvlConc();
    void downLvlConc(bool b);
    int getLvlConc();
    
    
private:
	
    sf::Sprite spr;
    int lvlConc;


    /*sf::Texture spriteSheet;
    
    sf::RectangleShape bg;
    
    sf::RectangleShape play;
    sf::RectangleShape credits;
    sf::RectangleShape exit;
    
    sf::RectangleShape so;
    */
    
};

#endif