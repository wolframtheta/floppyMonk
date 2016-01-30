#include "utils.hpp"

Monjo::Monjo() {

    /*sf::Texture monjoT;
    if (!monjoT.loadFromFile(file_monjo)) std::cout << "Failed to load monjo" << std::endl;
    spr.setTexture(monjoT);
    spr.setOrigin(160,160);
    spr.setPosition(//W_WIDTH/2,W_HEIGHT*2/3);
    */
    lvlConc = 1;
    pos.x = 840; //centrado, se puede hacer +-20 para movimiento sinusoidal.
    pos.y = 500; //y-suelo = 500, y-techo = 0

}

void Monjo::upLvlConc() {
    lvlConc += 7;
}

//b és true si es falla la nota
//b és false si es pitja la tecla incorrecta
void Monjo::downLvlConc(bool b) {
    if (b) lvlConc -= 5;
    else lvlConc -= 3;
}

int Monjo::getLvlConc() {
    return lvlConc;
}

void Monjo::update(){
	
	//window->draw(spr);
	
	
}

sf::Vector2f Monjo::getPos(){
    
    return pos;
    
}