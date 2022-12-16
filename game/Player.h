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
	void displayLife();
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
	location = -1;
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
	cout << "Move " << name << " Right" << endl;
	if (location < numRooms) {
		location++;
	}
}

int Player::getLoc() {
	return location;
}

void Player::displayLife() {
	cout << name << " life is: " << startLife << "\n\n";
}

int Player::getLife() {
	return startLife;
}

void Player::reduceLife() {
	startLife--;
}
