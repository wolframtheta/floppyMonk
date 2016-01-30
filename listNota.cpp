#include "utils.hpp"

listNota::listNota(){
	
	tempo = 1;
	zona.left = 1520;
	zona.top = W_HEIGHT*3/4+20;
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
		if ((*it).getType() == type){
			if ((*it).encert(zona)){
				//(*it).playmusic;			TO DO
				listNotes.erase(it--);
				trobada = true;
			}
		}
		++it;
	}

	return trobada;
	
}
