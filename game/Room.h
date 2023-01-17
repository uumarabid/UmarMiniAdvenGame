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