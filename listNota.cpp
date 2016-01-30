#include "utils.hpp"

listNota::listNota(int freq) {
	this.freq = freq;
}

listNota::newNota() {
	list<Nota>::iterator it;
	it = listNota.end();
	Nota nota(rand() % 4 +1);
	it.insert(nota);
}