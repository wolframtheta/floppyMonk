#ifndef _LISTNOTA_HPP
#define _LISTNOTA_HPP

class listNota {

public:
	
	listNota();
	void newNota();
	float getTempo();
	void update();

private:
	std::list<Nota> listNotes;
	
	//el tempo conta segons entre notes
	float tempo = 1.0;

};

#endif