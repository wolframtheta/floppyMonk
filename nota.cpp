#include "utils.hpp"
#include "nota.hpp"

Nota::Nota(int nota){
	// type és la columna que l'hi toca a la nota
	//	|	|	|	|	\\
	//	q	w	e	r	\\
	//	|	|	|	|	\\	
	
	type = nota;
	
	sf::Texture texture;
	if (!texture.loadFromFile("./images/spriteSheet.jpg")) std::cout << "Error al carregar la textura" << std::endl;
	spr.setTexture(texture);
	//spr.setTextureRect(a,b,c,d); falta posar les dimensions del rectangle aka REKT!!
	
	spr.setPosition(sf::Vector2f((W_WIDTH/5) * type,0));
}

void Nota::dibuixarNota(sf::RenderWindow* window){
	spr.move(0,1):
	window.draw(spr);
}