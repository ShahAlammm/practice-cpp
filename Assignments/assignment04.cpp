/*
Name: Shah Alam
Section: 12
Assignment: 04 - Text-Based Adventure Game
Date: 18 February 2026
*/

#include <iostream>
#include <limits>
using namespace std;

//  GLOBAL SCORE 
int gold = 0;

//  FUNCTION TO PRINT STATUS 
void showGoldStatus() {
    cout << "\nGold collected: " << gold << endl;
}

//  Input helper to handle bad input 
int getValidChoice() {
    int choice;
    cin >> choice;
    return choice;
}

//  ROOM 1 : Entrance 
int room1() {
    cout << "\n=== Room 1: Building Entrance ===\n";
    cout << "You stand at the dark mouth of an old building.\n";
showGoldStatus();

    cout << "1. Go north  -> Treasure Room\n";
    cout << "2. Go east   -> Monster Lair\n";
    cout << "Choice: ";

int choice = getValidChoice();

if (choice == 1) return 2;
if (choice == 2) return 3;

cout << "Invalid choice. You stay put.\n";
return 1;
}

//  ROOM 2 : Treasure Room 
int room2() {
static bool firstVisit = true;

    cout << "\n=== Room 2: Treasure Room ===\n";

if (firstVisit) {
    cout << "Sunlight glints off a small pile of coins!\n";
    cout << "You collect 25 gold pieces.\n";
    gold += 25;
    firstVisit = false;
} else {
    cout << "The treasure is empty now.\n";
}

    showGoldStatus();

cout << "1. Go south  -> Entrance\n";
cout << "2. Go east   -> Exit Room\n";
cout << "Choice: ";

int choice = getValidChoice();

if (choice == 1) return 1;
if (choice == 2) return 4;

cout << "Invalid choice. You stay here.\n";
return 2;
}

//  ROOM 3 : Monster Room 
int room3() {
static bool firstVisit = true;

cout << "\n=== Room 3: Monster Lair ===\n";

if (firstVisit) {
    cout << "A shadowy creature attacks your pouch!\n";
    cout << "You lose 8 gold pieces.\n";
    gold -= 8;
if (gold < 0) gold = 0;
    firstVisit = false;
} else {
    cout << "The monster is gone... only claw marks remain.\n";
}

showGoldStatus();

cout << "1. Go west   -> Entrance\n";
cout << "2. Go north  -> Exit Room\n";
cout << "Choice: ";

int choice = getValidChoice();

if (choice == 1) return 1;
    if (choice == 2) return 4;

cout << "Invalid choice. You stay here.\n";
return 3;
}

//  ROOM 4 : Exit Room 
int room4() {
cout << "\n=== Room 4: Exit Room ===\n";
cout << "Exit ahead -->\n";
showGoldStatus();

if (gold >= 20) {
cout << "You win!\n";
} else {
cout << "You escaped....\n";
}

cout << "\n1. Go back to Treasure Room\n";
cout << "2. Go back to Monster Lair\n";
cout << "3. Exit the room (quit)\n";
cout << "Choice: ";

int choice = getValidChoice();

if (choice == 1) return 2;
if (choice == 2) return 3;
if (choice == 3) return 0;

cout << "Invalid choice. You hesitate at the exit...\n";
return 4;
}

//  MAIN GAME LOOP 
int main() {

int currentRoom = 1;

cout << "==*== ROOM OF GOLD ==*==\n";
cout << "Collect gold and try to escape!\n";

 while (currentRoom != 0) { // main game loop for room checking.

switch (currentRoom) {
case 1: 
currentRoom = room1(); 
break;
case 2: 
currentRoom = room2(); 
break;
case 3: 
currentRoom = room3(); 
break;
case 4: 
currentRoom = room4(); 
break;
default:
cout << "(Error: Invalid room)\n";
currentRoom = 0;
}
}

cout << "\n*****===***** Game Over ******===******\n";
cout << "Final gold collected: " << gold << endl;

if (gold >= 20)
cout << "Great job!\n";
else
cout << "You survived....\n";

return 0;
}