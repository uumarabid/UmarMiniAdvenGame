#pragma once

#include <random>
#include "color.h"

class Dragon {
public:
	int dragonLife;
	Dragon(Player* myPlayer);
	int getDragonLife();

};

//constructor body
Dragon::Dragon(Player* myPlayer) {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(1, 10); // define the range

	this->dragonLife = distr(gen);

	cout << "\nYou are fighting the dragon";
	cout << "\n\nDragon's life: " << getDragonLife();

	cout << "\n\nPlayer's life:" << myPlayer->getLife();

	if (getDragonLife() > myPlayer->getLife()) {
		cout << "\n\nDragon Won";
	}
	else if (getDragonLife() == myPlayer->getLife()) {
		cout << "\n\nMatch withdraw";
	}
	else {
		cout << "\n\nPlayer Won";
	}
}

int Dragon::getDragonLife() {
	return this->dragonLife;
}
