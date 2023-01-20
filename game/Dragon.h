#pragma once

#include <random>
#include "Color.h"
using namespace std;

class Dragon {
private:
	int returnRandomNumber();
public:
	int dragonLife;
	Dragon(Player* myPlayer);
	int getDragonLife();

};

// constructor body
// generate dragon's life, and fight with dragon.
Dragon::Dragon(Player* myPlayer) {

	dragonLife = returnRandomNumber();

	cout << "\nYou are fighting the dragon";
	cout << "\n\nDragon's life: " << dye::red(getDragonLife());

	cout << "\n\nPlayer's life: " << dye::green(myPlayer->getLife());

	if (getDragonLife() > myPlayer->getLife()) {
		cout << dye::red("\n\nDragon Won!!!!\n\n");
	}
	else if (getDragonLife() == myPlayer->getLife()) {
		cout << dye::yellow("\n\nMatch withdraw!!!!\n\n");
	}
	else {
		cout << dye::green("\n\nPlayer Won!!!!\n\n");
	}
}

// generate random life for the dragon
int Dragon::returnRandomNumber() {
	random_device rd; // obtain a random number from hardware
	mt19937 gen(rd()); // seed the generator
	uniform_int_distribution<> distr(9, 17); // define the range

	return distr(gen);
}

// return the dragon's life
int Dragon::getDragonLife() {
	return dragonLife;
}
