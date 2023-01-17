#pragma once
#include <iostream>
#include<string>
#include "Color.h"
#include <iostream>
#include <iomanip>

using namespace std;

// room class
class Position {
	//private:
	//	string description;
	//	bool dragon;
public:
	int locationGrid[8][8];
	int locationInformation[8][8];
	int x = 0;
	int y = 0;

	Position();

	char moveUp();
	char moveDown();
	char moveLeft();
	char moveRight();
	char userPosition();
	void locationSetup();
};

//constructor body
Position::Position() {
	locationSetup();
	userPosition();
}


// set the position of life(l), treature(t) and dragon(d). 
void Position::locationSetup() {
	locationInformation[0][3] = 'l';
	locationInformation[1][5] = 'l';
	locationInformation[2][0] = 't';
	locationInformation[2][5] = 'l';
	locationInformation[5][6] = 'l';
	locationInformation[3][6] = 'd';
	locationInformation[4][5] = 'l';
	locationInformation[4][3] = 'l';
	locationInformation[6][5] = 'l';
	locationInformation[7][2] = 't';
}

char Position::moveLeft() {
	if (y > 0)
		y--;
	return userPosition();
}
char Position::moveRight() {
	if (y < 7)
		y++;
	return userPosition();
}
char Position::moveUp() {
	if (x > 0)
		x--;
	return userPosition();
}
char Position::moveDown() {
	if (x < 7)
		x++;
	return userPosition();
}

// display a grid of 8 x 8 rooms
char Position::userPosition() {
	try
	{
		int localx = x, localy = y;
		char grid[8][8];
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				grid[i][j] = '.';
			}
		}
		grid[localx][localy] = '*';

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (grid[i][j] == '*') {
					cout << dye::purple(grid[i][j]) << " ";
				}
				else if (i == 3 && j == 6) {
					cout << dye::red(grid[i][j]) << " ";
				}
				else {
					cout << grid[i][j] << " ";
				}

			}
			cout << endl;
		}
		cout << "\n\n";
		char information =  locationInformation[x][y];
		locationInformation[x][y] = 'n';
		return information;
	}
	catch (const exception&)
	{

	}
}