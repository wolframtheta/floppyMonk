#ifndef _NOTA_HPP_
#define _NOTA_HPP_

class Nota{
    
public:
    
    Nota(int);
    ~Nota();

	void dibuixarNota(sf::RenderWindow* window);    
    //fer sonar la nota
        
private:
    
	// 1 = q    2 = w   3 = e   4 = r
    int type;
    sf::Sprite spr;
    //falta posar el so
    
};
#endif	