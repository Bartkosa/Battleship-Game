#pragma once

class ship {

	int length;
	std::string name;
	bool is_alive;
public:

	ship(int l=2, std::string n= "no name", bool i=0);
	ship(ship&);
	ship& operator=(const ship& rh);
	
	void setShipName(std::string s);
	void setShipLength(int l);
	void setShipStatus(bool a);
	std::string getShipName();
	int getShipLength();
	bool getShipStatus();

	friend std::istream& operator >> (std::istream& in, ship& s);
	friend std::ostream& operator << (std::ostream& i, const ship& s);



};