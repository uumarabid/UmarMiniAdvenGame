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
	string getDescription();
	bool getDragon();
};

//constructor body
Room::Room(string description, bool dragon) {
	this->description = description;
	this->dragon = dragon;
}

string Room::getDescription() {
	return this->description;
}
bool Room::getDragon() {
	return this->dragon;
}