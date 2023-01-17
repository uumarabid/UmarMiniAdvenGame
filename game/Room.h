#pragma once
#include <iostream>
#include<string>
#include "Color.h"

using namespace std;

// room class
class Room {
private:
	string description;
	bool dragon;
public:
	int locationGrid[8][8];
	int x = 0;
	int y = 0;
	//constructor
	Room(string description, bool dragon);
	void getDescription();
	bool getDragon();
	void exploreRoom(Player* myPlayer);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void userPosition();
};

//constructor body
Room::Room(string description, bool dragon) {
	this->description = description;
	this->dragon = dragon;
}

// get location of the room
void Room::getDescription() {
	cout << "\nLocation: " << dye::purple(this->description) << "\n";
}

// check if there is a dragon in the room
bool Room::getDragon() {
	return this->dragon;
}

// explore room, if there is a dragon in room, reduce the life of player
void Room::exploreRoom(Player* myPlayer) {
	if (dragon) {
		myPlayer->reduceLife();
	}
}

void Room::moveUp() {
	if (y > 0)
		y--;
	userPosition();
}
void Room::moveDown() {
	if (y < 5)
		y++;
	userPosition();
}
void Room::moveLeft() {
	if (x > 0)
		x--;
	userPosition();
}
void Room::moveRight() {
	if (x < 5)
		x++;
	userPosition();
}
void Room::userPosition() {
	cout << "[" << x << "][" << y << "]";
}