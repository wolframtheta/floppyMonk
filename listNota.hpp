#ifndef _LISTNOTA_HPP
#define _LISTNOTA_HPP

class listNota {

public:
	
	listNota();
	void newNota();
	float getTempo();
	bool update();
	bool encertaNota(int);
	std::list<Nota> listNotes;

private:
	
	//el tempo conta segons entre notes
	float tempo;
	sf::IntRect zona;

};

#endif