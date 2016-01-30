#include "utils.hpp"

Monjo::Monjo() {
	
    //spr.setTexture(spriteSheet);
	//spr.setTextureRect(a,b,c,d); falta posar les dimensions del rectangle aka REKT!!
	spr.setSize(150,100);
	spr.setFillColor(sf::Color(0,0,0));
	
	
    lvlConc = 1;
	spr.setPosition(W_WIDTH/2,W_HEIGHT*2/3);
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

void Monjo::update(RenderWindow* window){
	
	window.draw(spr);
	
	
}