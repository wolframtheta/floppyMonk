#include "utils.hpp"

listNota::listNota(int freq) {
	this.freq = freq;
}

void listNota::newNota() {
	std::list<Nota>::iterator it;
	it = listNotas.end();
	Nota nota(rand() % 4 +1);
	it.insert(nota);
}