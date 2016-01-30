#include "utils.hpp"

listNota::listNota(){
	
	tempo = 1;
	
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
			(*it).erase;
			it--;
			notaPerduda = true;
		}
	}
	
	//Play background music
	
	return notaPerduda;
}

bool listNota::encertaNota(int type){
	
	bool trobada = false;
	
	std::list<Nota>::iterator it = listNotes.begin();
	while (it != listNotes.end() and not trobada){
		if ((*it).getType() == type){
			if ((*it).encert()){
				//(*it).playmusic;			TO DO
				(*it).erase;
				it--;
				trobada = true;
			}
		}
	}

	return trobada;
	
}
