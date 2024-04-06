#pragma once
#include "Bogie.h"
#include <string.h>

class Train {
private:
	Bogie *engine;
	Bogie *Bogies;
	int TBogies;
	float Length;
public:
	Train();
	void TrainMaker(int x);
	void drawTrain(sf::RenderWindow &);
	bool addBogie();
	void removeBogie(sf::RenderWindow &, tgui::Gui &);
	void printTrain();
	bool SearchBogie(int ID);
	void ViewBogie();
	void addPassengers();
	void removePassengers();
	void viewPassengers();
	bool compare(char* P1, char* P2);
	void DataExtraction();
	void DataSaving();
	void RecordSaving();
	~Train();
};
