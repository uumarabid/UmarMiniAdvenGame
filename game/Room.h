#pragma once
#include <iostream>
#include<string>
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
};

//constructor body
Room::Room(string description, bool dragon) {
	this->description = description;
	this->dragon = dragon;
}

//remove this later
void Room::getDescription() {
	cout << "Location: " << this->description << "\n";
}

bool Room::getDragon() {
	return this->dragon;
}