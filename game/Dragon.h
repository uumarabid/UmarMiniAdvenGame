#pragma once

#include <random>

class Dragon {
public:
	int dragonLife;
	Dragon();
	int getDragonLife();

};

//constructor body
Dragon::Dragon() {
	//this->playerLife = playerLife;
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(1, 10); // define the range

	this->dragonLife = distr(gen);
}

int Dragon::getDragonLife() {
	return this->dragonLife;
}
