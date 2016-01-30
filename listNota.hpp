#ifndef _LISTNOTA_HPP
#define _LISTNOTA_HPP

class listNota {

public:
	
	listNota();
	void newNota();
	float getTempo();
	void update();
	bool encertaNota(int);

private:
	std::list<Nota> listNotes;
	
	//el tempo conta segons entre notes
	float tempo ;

};

#endif