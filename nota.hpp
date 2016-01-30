#ifndef _NOTA_HPP_
#define _NOTA_HPP_

class Nota{
    
public:
    
    Nota(int);
    ~Nota();

	void update();
	bool fora();
	bool encert(sf::IntRect);
	int getType();
	sf::Vector2f getPos();
	
private:
    
	// 1 = q    2 = w   3 = e   4 = r
    int type;
	sf::Vector2f pos;
    
};
#endif	