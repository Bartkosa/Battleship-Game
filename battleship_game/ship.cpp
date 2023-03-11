#include <iostream>
#include <string>
#include "ship.h"

using namespace std;

ship::ship(int l, string n, bool i) : length(l), name(n), is_alive(i) {
	
}

ship::ship(ship& shipV2) {
	string name2 = shipV2.name;
	name = name2;
	length = shipV2.length;
	is_alive = shipV2.is_alive;
}

ship& ship::operator=(const ship &rh) {
	if (this == &rh) return *this;

	this->length = rh.length;
	this->name = rh.name;
	this->is_alive = rh.is_alive;

	return *this;
}

void ship::setShipName(string s) {
	name = s;
}
void ship::setShipLength(int l) {
	length = l;
}
void ship::setShipStatus(bool a) {
	is_alive = a;
}
int ship::getShipLength() {
	return length;
}
bool ship::getShipStatus() {	
	return is_alive;
}
string ship::getShipName() {
	return name;
}

istream& operator >> (istream& in, ship& s) {
	cout << "What's the length of the ship?: (2 / 3 / 4 / 5) ";
	cin >> s.length;
	cout << "And the name of the ship?: ";
	cin >> s.name;

	return in;
}

ostream& operator << (ostream& out, const ship& s) {
	cout << "Length: " << s.length << endl << "Name: " << s.name << endl << "Is  alive?: ";
	if (s.is_alive == 1) cout << "yes" << endl;
	else cout << "no" << endl;
	return out;
}


