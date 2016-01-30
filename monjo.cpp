#include "utils.hpp"
#include <cmath>
Monjo::Monjo() {

    /*sf::Texture monjoT;
    if (!monjoT.loadFromFile(file_monjo)) std::cout << "Failed to load monjo" << std::endl;
    spr.setTexture(monjoT);
    spr.setOrigin(160,160);
    spr.setPosition(//W_WIDTH/2,W_HEIGHT*2/3);
    */
    lvlConc = 1;//MAX 250
    pos.x = 840; //centrado, se puede hacer +-20 para movimiento sinusoidal.
    pos.y = 500; //y-suelo = 500, y-techo = 0
    health = 100;
    overflow = -126;

}

void Monjo::upLvlConc() {
    if(lvlConc<251)
         lvlConc += 1;
    pos.y=500- lvlConc*2;

}

//b és true si es falla la nota
//b és false si es pitja la tecla incorrecta
void Monjo::downLvlConc(bool b) {
    healthDown();
    if (b)
    {
        lvlConc -= 2;
    } 
    else 
    {
        lvlConc -= 1;
    }
    if(lvlConc<0) lvlConc=0;
    pos.y=500- lvlConc*2;

}

int Monjo::getLvlConc() {
    return lvlConc;
}

//Byte Monjo::posrel = 0;
void Monjo::update(float s){
	
    if (pos.y < 450) pos.x=840+10*sin(s);
	//window->draw(spr);
	//++posrel;//0.1575

	
}

sf::Vector2f Monjo::getPos(){
    
    return pos;
    
}


void Monjo::healthDown()
{


    health = health - maxim(5,lvlConc*0.2);

}
int Monjo::getHp() { 
    return health; 
}

void Monjo::regHp() {
    overflow+=3;
    if (overflow<=-124 and health<100)++health;
}