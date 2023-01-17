// game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include "Player.h"
#include "Dragon.h"
#include "Room.h"
#include "Color.h"
#include "GameLoading.h"
#include <conio.h>
#include "Position.h"


using namespace std;

const int numOfRooms = 5;
int main()
{

	cout << dye::green("Please wait while the game is loading") << "\n\n";

	GameLoading* gameLoading = new GameLoading();
	gameLoading->Loading();

	Player* myPlayer;
	myPlayer = new Player();
	cout << "Hello and welcome " << myPlayer->getName() << "! \n";
	myPlayer->displayLife();

	Position* position = new Position();

	while (true) {
		string currentPosition;
		//cout << "take action: up, down, left, right";
		int key = _getch();
		
		if (key == 72) {
			position->moveUp();
		}
		else if (key == 80) {
			position->moveDown();
		}
		else if (key == 75) {
			position->moveLeft();
		}
		else if (key == 77) {
			position->moveRight();
		}
	}



	///////////////test code



	//create a pointer to player object
	//Player* myPlayer;

	////create a dynamic pointer array with pointers to room objects
	//Room* world[numOfRooms] = {
	//	new Room("Blue Room", false),
	//	new Room("Green Room",false),
	//	new Room("Yellow Room", true),
	//	new Room("Red Room", false),
	//	new Room("pink Room", false),
	//};

	////point myPlayer to new player
	//myPlayer = new Player(numOfRooms);

	//for (int i = 0; i < numOfRooms; i++) {
	//	myPlayer->moveRight();
	//	world[myPlayer->getLoc()]->exploreRoom(myPlayer);
	//	world[myPlayer->getLoc()]->getDescription();
	//	myPlayer->displayLife();
	//}

	//// call a function to get input from a player
	//char action = myPlayer->getAction();
	//Dragon* boss = new Dragon(myPlayer, action);

}

// keep looping until we get a b or a f from the player
// then return the character



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
