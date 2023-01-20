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

int main()
{

	cout << dye::green("Please wait while the game is loading") << "\n\n";

	GameLoading* gameLoading = new GameLoading();
	gameLoading->Loading();

	Player* myPlayer;
	myPlayer = new Player();
	cout << "Hello and welcome " << myPlayer->getName() << "! \n";
	cout << "The game objective is to defeat the dragon, You should collect more lives before you try to fight the dragon.\n\n";
	cout << "INSTRUCTIONS: You can use the arrow keys to move up, down, left, right.\n\n";
	

	Position* position = new Position();

	// keep taking actions until you fight the dragon. 
	// you can use the arrow keys to move between rooms. 
	while (true) {
		
		string currentPosition;
		cout << "\n\n\n";
		int key = _getch();
		char insideTheRooms = 'n';
		myPlayer->displayLife();
		if (key == 72) {
			insideTheRooms = position->moveUp();
		}
		else if (key == 80) {
			insideTheRooms = position->moveDown();
		}
		else if (key == 75) {
			insideTheRooms = position->moveLeft();
		}
		else if (key == 77) {
			insideTheRooms = position->moveRight();
		}
		Room* room = new Room(insideTheRooms);
		bool gameover = room->exploreRoom(myPlayer);
		if (gameover) {
			break;
		}
	}
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
