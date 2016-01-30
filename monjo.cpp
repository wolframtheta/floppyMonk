#include "utils.hpp"

Monjo::Monjo() {
	
    spr.setTexture(spriteSheet);
	//spr.setTextureRect(a,b,c,d); falta posar les dimensions del rectangle aka REKT!!
	
    lvlConc = 1;
	spr.setPosition(W_WIDTH/2,W_HEIGHT*2/3);
}

/*
void Monjo::setSprite(sf::Sprite sprite) {
    spr = sprite;
}
*/

void Monjo::upLvlConc() {
    lvlConc += 5;
}

//b és true si es falla la nota
//b és false si es pitja la tecla incorrecta
void Monjo::downLvlConc(bool b) {
    if (b) lvlConc -= 5;
    else lvlConc -= 2;
}
