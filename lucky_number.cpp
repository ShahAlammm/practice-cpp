/*
* Muhammad Akram
* CS1120
* Section 2!!!
* Assignment #4
* Text-Based Adventure Game
*/
#include <iostream>
#include <string>
using namespace std;
// Global score variable
int gold = 0;
// Function to show current score
void showScore() {
cout << "Gold Collected: " << gold << endl;
cout << "------------------------------" << endl;
}
// Room functions
int room1() {
static bool firstVisit = true;
cout << "\nYou are in a dark cave entrance mate." << endl;
if (firstVisit) {
cout << "You find 10 gold pieces on the ground mate!" << endl;
gold += 10;
firstVisit = false;
}
cout << "Options:\n1. Go to Room 2\n2. Go to Room 3\n3. Stay here mate" <<
endl;
showScore();
int choice;
cin >> choice;
if (choice == 1) return 2;
else if (choice == 2) return 3;
else return 1;
}
int room2() {
static bool firstVisit = true;
cout << "\nYou are in a treasure chamber ." << endl;
if (firstVisit) {
cout << "You open a chest and collect 20 gold!" << endl;
gold += 20;
firstVisit = false;
} else {
cout << "The chest is empty now lol." << endl;
}
cout << "Options:\n1. Go to Room 4\n2. Return to Room 1" << endl;
showScore();
int choice;
cin >> choice;
if (choice == 1) return 4;
else return 1;
}

int room3() {
cout << "\nYou are in a narrow hallway. It feels spooky." << endl;
cout << "Options:\n1. Return to Room 1\n2. Go to Room 4" << endl;
showScore();
int choice;
cin >> choice;
if (choice == 1) return 1;
else return 4;
}
int room4() {
cout << "\nYou are in the final chamber. A guardian blocks the exit." << endl;
cout << "You pay 5 gold to pass." << endl;
if (gold >= 5) {
gold -= 5;
cout << "The guardian lets you through. You win!" << endl;
} else {
cout << "You don’t have enough gold! The guardian pushes you back." <<
endl;
return 2; // Send back to treasure room
}
showScore();
return 0; // 0 means game ends
}
int main() {
cout << "Welcome to the Adventure Game buddy!" << endl;
int currentRoom = 1;
while (currentRoom != 0) {
switch (currentRoom) {
case 1: currentRoom = room1(); break;
case 2: currentRoom = room2(); break;
case 3: currentRoom = room3(); break;
case 4: currentRoom = room4(); break;
default: currentRoom = 0; break;
}
}
cout << "Game Over. Final Gold: " << gold << endl;
return 0;
}