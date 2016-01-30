#ifndef _LISTNOTA_HPP
#define _LISTNOTA_HPP

class listNota {

public:
	void newNota();
	listNota(int freq);


private:
	list<Nota> listNota;
	int freq;

};

#endif