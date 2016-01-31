#include "utils.hpp"
#include "nota.hpp"

Nota::Nota(int nota,bool left){
	// type és la columna que l'hi toca a la nota
	//	|	|	|	|	\\
	//	q	w	e	r	\\
	//	|	|	|	|	\\	
	
	type = nota;
        uiop = left;
	
	if (uiop) {
            pos.x = posRectangle2.x + 20;
            pos.y = -40;
        } else {
            pos.x = posRectangle.x + 20;
            pos.y = -40;
        }
	
}

Nota::~Nota(){

}


void Nota::update(){

	pos.y+=5;

}

bool Nota::fora(){
	
	return (pos.y > W_HEIGHT);
	
}

bool Nota::encert(sf::IntRect zona){
	sf::IntRect hbNote(pos.x,pos.y,80,80);
	return (hbNote.intersects(zona));
	
}

int Nota::getType(){
	
	return type;
	
}

sf::Vector2f Nota::getPos() {
	return pos;
}
