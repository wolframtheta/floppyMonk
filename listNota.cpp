#include "utils.hpp"

listNota::listNota(float tempo) {
	this.tempo = tempo;
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
