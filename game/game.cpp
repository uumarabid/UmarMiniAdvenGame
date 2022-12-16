// game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include "color.h"
#include "Player.h"
#include "Dragon.h"
#include "Room.h"
using namespace std;




const int numOfRooms = 5;
char getAction();


int main()
{
	cout << "Hello and welcome!\n";

	//create a pointer to player object
	Player* myPlayer;

	//create a dynamic pointer array with pointers to room objects
	Room* world[numOfRooms] = {
		new Room("Blue Room", false),
		new Room("Green Room",false),
		new Room("Yellow Room", true),
		new Room("Red Room", false),
		new Room("pink Room", false),
	};

	//point myPlayer to new player
	myPlayer = new Player(numOfRooms);

	for (int i = 0; i < numOfRooms; i++) {
		myPlayer->moveRight();
		world[myPlayer->getLoc()]->exploreRoom(myPlayer);
		world[myPlayer->getLoc()]->getDescription();
		myPlayer->displayLife();
	}

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
