#pragma once
#include <iostream>
#include<string>
#include "Color.h"

using namespace std;

// room class
class Room {
private:
	char insideTheRoom;
public:
	//constructor
	Room(char insideTheRoom);
	bool exploreRoom(Player* myPlayer);
};

//constructor body
Room::Room(char insideTheRoom) {
	this->insideTheRoom = insideTheRoom;
}


// explore room, if there is a dragon in room, reduce the life of player
bool Room::exploreRoom(Player* myPlayer) {
	bool gameOver = false;

	if (insideTheRoom == 'n') {
		cout << dye::yellow("There is nothing in the room") << "\n\n";
	}
	else if (insideTheRoom == 'l') {
		myPlayer->increaseLife();
	}
	else if (insideTheRoom == 'd') {
		Dragon* boss = new Dragon(myPlayer);
		gameOver = true;
	}
	return gameOver;
}