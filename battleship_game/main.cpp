#include <iostream>
#include "ship.h"
#include "battleship.h"

using namespace std;

int main() {
	battleship p1, p2;
	cout << "PLAYER 1: " << endl;
	cin >> p1;
	system("CLS");
	cout << "PLAYER 2: " << endl;
	cin >> p2;
	battleship p1_view, p2_view;

	bool ok = 1;
	while (ok == 1) {
		bool are_all_dead = 1;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (p1.getMap(i, j) == 1) {
					are_all_dead = 0;
				}
			}
		}
		if (are_all_dead == 1) {
			ok = 0;
			cout << "PLAYER 2 WON" << endl;
			break;
		}
		are_all_dead = 1;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (p2.getMap(i, j) == 1) {
					are_all_dead = 0;
				}
			}
		}
		if (are_all_dead == 1) {
			ok = 0;
			cout << "PLAYER 1 WON" << endl;
			break;
		}
		system("pause");
		system("CLS");
		cout << "PLAYER 1 TURN: " << endl;
		system("pause");

		cout << "Your map: "<< endl<< p1;
		system("pause");
		system("CLS");
		cout << "Your opponent map: " << endl<<p2_view;
		int column, line;
		string columnV2;
		cout << "Enter the coordinates you want to hit: " << endl;
		cout << "column: ";
		cin >> columnV2;
		if (columnV2[0] == '1' && columnV2[1] == '0') column = 10;
		else column = columnV2[0] - 'a';
		cout << "line: ";
		cin >> line;

		p2.setMap(column, line - 1);
		p2.setMap(column, line - 1);
		p2_view.setMap(column, line - 1);
		p2_view.setMap(column, line - 1);
		system("CLS");
		if (p2.getMap(column, line - 1) == 3) {
			cout << "Wow! You have hit the " << p2.getShip()->getShipName() << endl << endl;
			p2_view.setMap(column, line - 1);
		}
		else
			cout << "MISS :(" << endl << endl;
		cout<<p2_view;

		system("pause");
		system("CLS");

		cout << "PLAYER 2 TURN: " << endl;
		system("pause");
		
		cout << "Your map: " << endl << p2;
		system("pause");
		system("CLS");
		cout << "Your opponent map: " << endl << p1_view;
		
		cout << "Enter the coordinates you want to hit: " << endl;
		cout << "column: ";
		cin >> columnV2;
		if (columnV2[0] == '1' && columnV2[1] == '0') column = 10;
		else column = columnV2[0] - 'a';
		cout << "line: ";
		cin >> line;
		p1.setMap(column, line - 1);
		p1.setMap(column, line - 1);
		p1_view.setMap(column, line - 1);
		p1_view.setMap(column, line - 1);
		system("CLS");
		if (p1.getMap(column, line - 1) == 3) {
			cout << "Wow! You have hit the " << p1.getShip()->getShipName() << endl << endl;
			p1_view.setMap(column, line - 1);
		}
		else
			cout << "MISS :(" << endl << endl;
		cout << p1_view;
	}
}