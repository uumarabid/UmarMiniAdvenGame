#pragma once

#include <iostream>
#include<string>
#include "Color.h"
using namespace std;

// class
class Player {
private:
	int location;
	string name;
	int startLife = 10;
	int numRooms;
public:
	// declaring constructor 
	Player();
	string getName();
	//int getLoc();
	void displayLife();
	int getLife();
	/*void moveRight();
	void moveLeft();*/
	void reduceLife();
	//char getAction();
};

//constructor body 
Player::Player() {
	string name;
	cout << "Please enter your name: ";
	cin >> name;

	this->name = name;
	/*this->numRooms = numRooms;
	location = -1;*/
}

// get the player's name
string Player::getName()
{
	return this->name;
}

//// move player left
//void Player::moveLeft() {
//	if (location > 0) {
//		location--;
//	}
//}
//
//// move player to right
//void Player::moveRight() {
//	cout << "Move " << name << " Right" << endl;
//	if (location < numRooms) {
//		location++;
//	}
//}

// return current location of player
//int Player::getLoc() {
//	return location;
//}

// display player's life
void Player::displayLife() {
	cout << name << " life is: " << dye::green(startLife) << "\n\n";
}

// return life of player
int Player::getLife() {
	return startLife;
}

// reduce the life of player
void Player::reduceLife() {
	startLife--;
}

//// take action: 1. bribe or fight
//char Player::getAction() {
//	char action{};
//
//	while ((action != 'f') && (action != 'b')) {
//		cout << "\nWould you like to fight or bribe?\n";
//		cout << dye::yellow("To fight enter 'f'\n");
//		cout << dye::aqua("To bribe enter 'b'\n");
//		cin >> action;
//	}
//
//	return action;
//}