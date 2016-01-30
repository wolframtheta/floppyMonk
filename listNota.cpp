#include "utils.hpp"

listNota::listNota(int tempo) {
	this.tempo = tempo;
}

void listNota::newNota() {
	std::list<Nota>::iterator it;
	it = listNotas.end();
	Nota nota(rand() % 4 +1);
	it.insert(nota);
}

int listNota::getTempo() {
	return tempo;
}