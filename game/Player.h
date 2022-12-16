#pragma once

#include <iostream>
#include<string>
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
	Player(int numRooms);
	string getName();
	int getLoc();
	int getLife();
	void moveRight();
	void moveLeft();
	void reduceLife();
};

//constructor body 
Player::Player(int numRooms) {
	string name;
	cout << "Please enter your name: ";
	cin >> name;

	this->name = name;
	this->numRooms = numRooms;
	location = 0;
}

string Player::getName()
{
	return this->name;
}

void Player::moveLeft() {
	if (location > 0) {
		location--;
	}
}

void Player::moveRight() {
	if (location < numRooms) {
		location++;
	}
}

int Player::getLoc() {
	return location;
}

int Player::getLife() {
	return startLife;
}

void Player::reduceLife() {
	startLife--;
}
