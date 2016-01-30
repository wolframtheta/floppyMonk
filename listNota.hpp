#ifndef _LISTNOTA_HPP
#define _LISTNOTA_HPP

class listNota {

public:
	void newNota();
	listNota(int freq);


private:
	std::list<Nota> listNotas;
	int freq;

};

#endif