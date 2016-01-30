#include "utils.hpp"

listNota::listNota(){
	
	tempo = 0.5;
	zona.left = posRectangle.x;
	zona.top = posRectangle.y;
	zona.width = 380;
	zona.height = 80;
	
}

void listNota::newNota() {
	Nota nota(rand() % 4 +1);
	listNotes.push_back(nota);
}

float listNota::getTempo(){
	return tempo;
}

bool listNota::update(){
	
	bool notaPerduda = false;
	
	std::list<Nota>::iterator it = listNotes.begin();
	while (it != listNotes.end()){
		(*it).update();

		if ((*it).fora()){
			listNotes.erase(it--);
			notaPerduda = true;
		}
		++it;
	}
	
	//Play background music

	return notaPerduda;
}

bool listNota::encertaNota(int type){
	
	bool trobada = false;
	
	std::list<Nota>::iterator it = listNotes.begin();
	while (it != listNotes.end() and not trobada){
		
		if ((*it).getType() == type) {
			if ((*it).encert(zona)){

				listNotes.erase(it--);
				trobada = true;
			}
		}
		++it;
	}

	return trobada;
	
}
