#include <iostream>
#include "battleship.h"
#include "ship.h"

using namespace std;

battleship::battleship(int number): number(number) {
	ships = new (nothrow) ship[number];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = 0;
		}
	}
}
battleship::~battleship() {
	delete[] this->ships;
}

void battleship::setMap(int column, int line) {
	map[column][line] ++;
}

int battleship::getMap(int column, int line) {
	return map[column][line];
}

int battleship::getNumber() {
	return number;
}

ship* battleship::getShip() {
	return ships;
}

istream& operator >> (istream& in, battleship& b) {
	do {
		cout << "How many ships on the board? (1-10): ";
		cin >> b.number;
	} while (b.number < 1 || b.number>10);
	b.ships = new ship[b.number];
	string custom;
	do {
		cout << "Do you want to customize names of your ships? (yes / no): ";
		cin >> custom;
	} while (custom != "yes" && custom != "no");
	if (custom == "yes") {
		for (int i = 0; i < b.number; i++) {
			b.ships[i].setShipLength((i%4)+2);
			system("CLS");
			cout << b;
			cout << "What's the name of the ship of size " << b.ships[i].getShipLength() << "? ";

			string newName;
			cin >> newName;
			b.ships[i].setShipName(newName);
			b.ships[i].setShipStatus(1);
			//cout << b.ships[i];
			bool fits = 0;
			string columnX;
			int column;
			string vert;
			int line;
			do {
				system("CLS");
				cout << b;
				cout << "Write the coordinates of the ship of size " << b.ships[i].getShipLength() << endl;
				cout << "Column: ";
				cin >> columnX;
				if (columnX[0] == '1' && columnX[1] == '0') column = 10;
				else column = columnX[0] - 'a';
				cout << "Line: ";
				cin >> line;

				do {
					cout << "Vertically of horizontally?: (v / h)";
					cin >> vert;
				} while (vert != "h" && vert != "v");

				fits = 1;

				if (vert == "h") {
					if (column + b.ships[i].getShipLength() > 11) {
						fits = 0;
						cout << "It does not fit. Try again." << endl;
					}
					for (int j = 0; j < b.ships[i].getShipLength(); j++) {
						if (b.map[column + j][line - 1] == 1) {
							fits = 0;
							cout << "There is already a ship there. Try again." << endl;

						}
					}
				}
				else {
					if (line + b.ships[i].getShipLength() > 11) {
						fits = 0;
						cout << "It does not fit. Try again." << endl;
					}
					for (int j = 0; j < b.ships[i].getShipLength(); j++) {
						if (b.map[column][line + j - 1] == 1) {
							fits = 0;
							cout << "There is already a ship there. Try again." << endl;
						}
					}
				}
				if (fits == 0) {
					system("pause");
				}

			} while (fits == 0);

			for (int j = 0; j < b.ships[i].getShipLength(); j++) {
				if (vert == "h") {
					b.map[column + j][line - 1] = 1;
				}
				else {
					b.map[column][line + j - 1] = 1;
				}
			}
		}
	}
	else {
		for (int i = 0; i < b.number; i++) {
			b.ships[i].setShipLength((i % 4) + 2);
			
			switch (i % 4) {
			case 0:
				b.ships[i].setShipName("submarine");
				break;
			case 1:
				b.ships[i].setShipName("destroyer");
				break;
			case 2:
				b.ships[i].setShipName("cruiser");
				break;
			case 3:
				b.ships[i].setShipName("carrier");
				break;
			}
			b.ships[i].setShipStatus(1);
			//cout << b.ships[i];
			bool fits = 0;
			string columnX;
			int column;
			string vert;
			int line;
			do {
				system("CLS");
				cout << b;
				cout << "Write the coordinates of the ship of size " << b.ships[i].getShipLength()<< endl;
				cout << "Column: ";
				cin >> columnX;
				if (columnX[0] == '1' && columnX[1] == '0') column = 10;
				else column = columnX[0] - 'a';
				cout << "Line: ";
				cin >> line;
				
				do {
					cout << "Vertically of horizontally?: (v / h)";
					cin >> vert;
				} while (vert != "h" && vert != "v");

				fits = 1;
				
				if (vert == "h") {
					if (column + b.ships[i].getShipLength() > 11) {
						fits = 0;
						cout << "It does not fit. Try again." << endl;
					}
					for (int j = 0; j < b.ships[i].getShipLength(); j++) {
						if (b.map[column + j][line - 1] == 1) {
							fits = 0;
							cout << "There is already a ship there. Try again." << endl;
						}
					}
				}
				else {
					if (line + b.ships[i].getShipLength() > 11) {
						fits = 0;
						cout << "It does not fit. Try again." << endl;
					}
					for (int j = 0; j < b.ships[i].getShipLength(); j++) {
						if (b.map[column][line + j - 1] == 1) {
							fits = 0;
							cout << "There is already a ship there. Try again." << endl;
						}
					}
				}
				if (fits == 0) {
					system("pause");
				}

			} while (fits == 0);

			for (int j = 0; j < b.ships[i].getShipLength(); j++) {
				if (vert == "h") {
					b.map[column + j][line - 1] = 1;
				}
				else {
					b.map[column][line + j-1] = 1;
				}

			}
		}
	}
	
	return in;
}

ostream& operator << (ostream& out, const battleship& s) {
	cout << "   | a | b | c | d | e | f | g | h | i | j" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "---|---|---|---|---|---|---|---|---|---|---" << endl;
		if (i == 9) {
			cout << " " << i + 1;
		}
		else {
			cout << " " << i + 1 << " ";
		}
		for (int j = 0; j < 10; j++) {
			cout << "|";
			switch (s.map[j][i]) {
			case 0:
				cout << "   ";
				break;
			case 1:
				cout << "[o]";
				break;
			case 2:
				cout << " X ";
				break;
			case 3:
				cout << "[X]";
				break;
			}
		}
		cout << endl;
	}
	return out;
}