#ifndef _MONJO_HPP_
#define _MONJO_HPP_

class Monjo {
public:
	
    Monjo();
	
    //sf::Sprite getSprite();
	//void setSprite(sf::Sprite);
	
    void upLvlConc();
    void downLvlConc(bool);
    int getLvlConc();
    void update(float);
    void healthDown();
    int getHp();
    sf::Vector2f getPos();
    void regHp();

private:
    
    sf::Vector2f pos;
    //sf::Sprite spr;
    int lvlConc;
    int health;
    char overflow;
    /*sf::Texture spriteSheet;
    
    sf::RectangleShape bg;
    
    sf::RectangleShape play;
    sf::RectangleShape credits;
    sf::RectangleShape exit;
    
    sf::RectangleShape so;
    */
    
};

#endif