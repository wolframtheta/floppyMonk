#include "utils.hpp"

listNota::listNota(bool l){
	
	tempo = 1.0f;
        left = l;
	
        if (!left){
            zona.left = posRectangle.x;
            zona.top = posRectangle.y;
        } else {
            zona.left = posRectangle2.x;
            zona.top = posRectangle2.y;
        }
	zona.width = 380;
	zona.height = 80;

	
}

void listNota::newNota(int notesDisponibles) {
    
    if (left) notesDisponibles-=4;
    
    
    if (notesDisponibles > 0){
            
            Nota nota(rand()%notesDisponibles+1,left);
            listNotes.push_back(nota);
    }
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

void listNota::setTempo(float tmp)
{
	tempo=tmp;
}