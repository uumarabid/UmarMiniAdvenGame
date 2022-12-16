#pragma once
#include <iostream>
#include<string>
#include "color.h"

using namespace std;

// room class
class Room {
private:
	string description;
	bool dragon;
public:
	//constructor
	Room(string description, bool dragon);
	void getDescription();
	bool getDragon();
	void exploreRoom(Player* myPlayer);
};

//constructor body
Room::Room(string description, bool dragon) {
	this->description = description;
	this->dragon = dragon;
}

//remove this later
void Room::getDescription() {
	cout << "\nLocation: " << dye::purple(this->description) << "\n";
}

bool Room::getDragon() {
	return this->dragon;
}
void Room::exploreRoom(Player* myPlayer) {
	if (dragon) {
		myPlayer->reduceLife();
	}
	// somehrere here
}