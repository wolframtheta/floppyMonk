#ifndef _LISTNOTA_HPP
#define _LISTNOTA_HPP

class listNota {

public:
	
	listNota();
	void newNota();
	float getTempo();


private:
	std::list<Nota> listNotas;
	
	//el tempo conta segons entre notes
	float tempo = 1.0;

};

#endif