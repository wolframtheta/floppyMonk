#include "utils.hpp"
#include "nota.hpp"

Nota::Nota(int nota){
	// type és la columna que l'hi toca a la nota
	//	|	|	|	|	\\
	//	q	w	e	r	\\
	//	|	|	|	|	\\	
	
	type = nota;
	
	spr.setTexture(spriteSheet);
	//spr.setTextureRect(a,b,c,d); falta posar les dimensions del rectangle aka REKT!!
	float posx = 1920-400+20*type+40*(type-1);
	float posy = -40;
	spr.setPosition(sf::Vector2f(posx,posy));
	
}

void Nota::dibuixarNota(sf::RenderWindow* window){
	
	window.draw(spr);
	
}

void Nota::update(){

	spr.move(0,5);

}

bool Nota::fora(){
	
	return (spr.getPosition().y > W_HEIGHT);
	
}

bool Nota::encert(sf::IntRect zona){
	
	sf::IntRect hbNote(spr.getPosition().x,spr.getPosition.y,80,80);
	return (hbNote.intersects(zona));
	
}