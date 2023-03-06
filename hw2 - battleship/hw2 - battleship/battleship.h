#pragma once
#include <iostream>
#include <string>
#include "ship.h"

class battleship {

	int number;
	ship* ships;
	int map[10][10];

public:
	battleship(int number=10);
	~battleship();

	void setMap(int column, int line);
	int getMap(int column, int line);
	int getNumber();
	ship* getShip();
	

	friend std::istream& operator >> (std::istream& in, battleship& b);
	friend std::ostream& operator << (std::ostream& out, const battleship& s);

};