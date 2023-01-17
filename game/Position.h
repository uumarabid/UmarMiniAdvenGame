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
	int x = 0;
	int y = 0;

	Position();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void userPosition();
};

//constructor body
Position::Position() {

}

void Position::moveLeft() {
	if (y > 0)
		y--;
	userPosition();
}
void Position::moveRight() {
	if (y < 5)
		y++;
	userPosition();
}
void Position::moveUp() {
	if (x > 0)
		x--;
	userPosition();
}
void Position::moveDown() {
	if (x < 5)
		x++;
	userPosition();
}
void Position::userPosition() {
	int localx = x, localy = y; // position of the *
	char grid[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			grid[i][j] = '.';
		}
	}
	grid[localx][localy] = '*';
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
	cout << "\n\n";
}