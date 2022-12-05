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
    int numRooms;
public:
    // declaring constructor 
    Player(string name, int numRooms);
    string getName();
    int getLoc();
    void moveRight();
    void moveLeft();
};

//constructor body 
Player::Player(string name, int numRooms) {
    this->name = name;
    this->numRooms = numRooms;
    location = 0;
}

string Player::getName()
{
    return string();
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

// room class
class Room {
private:
    string description;
public:
    //constructor
    Room(string description);
    string getDescription();
};

int main()
{
    cout << "Hello World!\n";
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
