#pragma once

#include <random>
#include "color.h"

class Dragon {
private:
	int returnRandomNumber();
public:
	int dragonLife;
	Dragon(Player* myPlayer, char action);
	int getDragonLife();

};

//constructor body
Dragon::Dragon(Player* myPlayer, char action) {
	if (action == 'b') {
		cout << dye::red("\n\nYou are bribing, dragon wins\n\n");
	}
	else if (action == 'f') {

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
}

int Dragon::returnRandomNumber() {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(6, 12); // define the range

	return distr(gen);
}

int Dragon::getDragonLife() {
	return dragonLife;
}
