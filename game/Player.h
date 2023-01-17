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
	void displayLife();
	int getLife();
	void reduceLife();
	void increaseLife();
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

void Player::increaseLife() {
	startLife++;
	cout << dye::green("Your life has increased to ") << dye::blue(startLife) << "\n\n";
}
