// game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
	Player(string name, int numRooms);
	string getName();
	int getLoc();
	int getLife();
	void moveRight();
	void moveLeft();
	void reduceLife();
};

//constructor body 
Player::Player(string name, int numRooms) {
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

class Dragon {
private:
	int dragonLife;
public:
	//constructor
	Dragon();
	int getDragonLife();

};

//constructor body
Dragon::Dragon() {
	//this->playerLife = playerLife;
	int range = 10 - 1 + 1;
	this->dragonLife = rand() % range + 1;
}

int Dragon::getDragonLife() {
	return this->dragonLife;
}

const int numOfRooms = 4;
char getAction();


int main()
{
	cout << "Hello and welcome!\n";

	//create a pointer to player object
	Player* myPlayer;
	string playerName;

	cout << "Please enter your name: ";
	cin >> playerName;

	//create a dynamic pointer array with pointers to room objects
	Room* world[numOfRooms] = { new Room("Blue Room", false), new Room("Green Room",false), new Room("Yellow Room", true), new Room("Red Room", false) };

	//point myPlayer to new player
	myPlayer = new Player(playerName, numOfRooms);

	// test
	cout << myPlayer->getName() << endl;

	// testing player movement
	cout << "Before moving. The location is: ";
	cout << world[myPlayer->getLoc()]->getDescription() << endl;

	cout << "Move " << myPlayer->getName() << " Right" << endl;
	myPlayer->moveRight();
	if (world[myPlayer->getLoc()]->getDragon()) {
		myPlayer->reduceLife();
	}


	cout << "After moving right. The location is: ";
	cout << world[myPlayer->getLoc()]->getDescription() << endl;
	cout << "Your life is: ";
	cout << myPlayer->getLife() << endl;

	cout << "Move " << myPlayer->getName() << " Right again" << endl;
	myPlayer->moveRight();
	if (world[myPlayer->getLoc()]->getDragon()) {
		myPlayer->getLife();
	}

	cout << "After moving right. The location is: ";
	cout << world[myPlayer->getLoc()]->getDescription() << endl;
	cout << "Your life is: ";
	cout << myPlayer->getLife() << endl;

	if (world[myPlayer->getLoc()]->getDragon()) {
		myPlayer->reduceLife();
	}

	cout << "Move " << myPlayer->getName() << " Right again" << endl;
	myPlayer->moveRight();
	if (world[myPlayer->getLoc()]->getDragon()) {
		myPlayer->reduceLife();
	}

	cout << "After moving right. The location is: ";
	cout << world[myPlayer->getLoc()]->getDescription() << endl;
	cout << "Your life is: ";
	cout << myPlayer->getLife() << endl;


	// call a function to get input from a player
	char action = getAction();

	if (action == 'f') {
		cout << "\nYou are fighting the dragon";
		Dragon* boss = new Dragon();
		
		cout << "\nDragon's life: " << boss->getDragonLife();

		cout << "\nPlayer's life:" << myPlayer->getLife();

		if (boss->getDragonLife() > myPlayer->getLife()) {
			cout << "\nDragon Won";
		}
		else if (boss->getDragonLife() == myPlayer->getLife()) {
			cout << "\nMatch withdraw";
		}
		else {
			cout << "\nPlayer Won";
		}
		
	}

	if (action == 'b') {
		cout << "You are bribing, dragon wins\n";
	}

}

// keep looping until we get a b or a f from the player
// then return the character

char getAction() {
	char action{};

	while ((action != 'f') && (action != 'b')) {
		cout << "\nWould you like to fight or bribe?\n";
		cout << "To fight enter 'f'\n";
		cout << "To bribe enter 'b'\n";
		cin >> action;
	}

	return action;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
