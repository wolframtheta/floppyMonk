#include "utils.hpp"

Monjo::Monjo() {

    /*sf::Texture monjoT;
    if (!monjoT.loadFromFile(file_monjo)) std::cout << "Failed to load monjo" << std::endl;
    spr.setTexture(monjoT);
    spr.setOrigin(160,160);
    spr.setPosition(//W_WIDTH/2,W_HEIGHT*2/3);
    */
    lvlConc = 100;
    pos.x = 840; //centrado, se puede hacer +-20 para movimiento sinusoidal.
    pos.y = 500; //y-suelo = 500, y-techo = 0

}

void Monjo::upLvlConc() {

    lvlConc += 7;
    pos.y--;
    if(pos.y<0) pos.y=0;
}

//b és true si es falla la nota
//b és false si es pitja la tecla incorrecta
void Monjo::downLvlConc(bool b) {
    if (b)
    {
        lvlConc -= 5;
        pos.y+=3;
        if(pos.y>500) pos.y=500;
    } 
    else 
    {
        lvlConc -= 3;
        pos.y+=2;
        if(pos.y>500) pos.y=500;
    }
}

int Monjo::getLvlConc() {
    return lvlConc;
}

//Byte Monjo::posrel = 0;
void Monjo::update(){
	
	//window->draw(spr);
	//++posrel;//0.1575

	
}

sf::Vector2f Monjo::getPos(){
    
    return pos;
    
}