#pragma once
#include <iostream>
#include<string>
#include "Color.h"

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

void Position::moveUp() {
	if (y > 0)
		y--;
	userPosition();
}
void Position::moveDown() {
	if (y < 5)
		y++;
	userPosition();
}
void Position::moveLeft() {
	if (x > 0)
		x--;
	userPosition();
}
void Position::moveRight() {
	if (x < 5)
		x++;
	userPosition();
}
void Position::userPosition() {
	cout << "[" << x << "][" << y << "]";
}