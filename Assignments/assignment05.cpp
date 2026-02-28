/*
Name: Shah Alam
Section: 12
Assignment: 05
Date: 25 February 2026
*/

#include <iostream>
using namespace std;


int gold = 0;

// Condition 01:
// user pick a number between lower and upper for choice input.
int menu(int lower, int upper) {

    int choice;

while (true) {
 cout << "Please enter a choice (" << lower << " to " << upper << "): ";
 cin >> choice;

if (choice >= lower && choice <= upper) { // valid choice here.
    return choice; 
} else {
    cout << "Invalid. Please choose a number between " << lower << " and " << upper << ".\n";
}
}
}

// Condition 02:  NIM GAME
// to leave Room 3 player must play nim game and win against the "Monster".

void nim() {
bool playerWon = false;
while (!playerWon) {
int sticks = 10;
int take;
        
cout << "\n--- THE NIM CHALLENGE ---\n";
cout << "You must win Nim to leave! There are 10 sticks.\n";
cout << "The person who takes the last stick loses. !!\n";

while (sticks > 0) {
// Player Turn
cout << "Sticks remaining: " << sticks << "\nHow many do you ta(1-3)? ";
take = menu(1, 3);
sticks -= take;

if (sticks <= 0) {
 cout << "You took the last stick! You lose. Restarting Nim...\n";
 break; 
 }

// computer Turn
int computerTake = (sticks % 4 == 0) ? 1 : sticks % 4;
if (computerTake == 0) computerTake = 1;
cout << "The Monster takes " << computerTake << " sticks.\n";
sticks -= computerTake;

if (sticks <= 0) {
    cout << "The Monster took the last stick! YOU WIN!\n";
    playerWon = true;
 }
}
}
}

// Condition 03:
// Solves a math problem for bonus gold
void riddle() {
int answer;
cout << "\n--- THE RIDDLE STATUE ---\n";
cout << "Solve this to prove your wit: What is 12 multiplied by 3, plus 4?\n";
answer = menu(1, 100); 

if (answer == 40) {
    cout << "Correct! The statue drops 15 gold.\n";
    gold += 15;
} else {
    cout << "Incorrect. The statue remains silent.\n";
}
}

void showGoldStatus() {
    cout << "\nGold collected: " << gold << endl;
}

// --- ROOM FUNCTIONS ---

int room1() {
cout << "\n=== Room 1: Building Entrance ===\n";
cout << "You stand at the dark mouth of an old building.\n";
showGoldStatus();
cout << "1. Go north -> Treasure Room\n";
cout << "2. Go east  -> Monster Lair\n";
    
int choice = menu(1, 2);
if (choice == 1) return 2;
return 3;
}

int room2() {
    static bool riddleDone = false;
cout << "\n=== Room 2: Treasure Room ===\n";
cout << "Sunlight glints off the walls.\n";
showGoldStatus();
    
cout << "1. Go south -> Entrance\n";
cout << "2. Go east  -> Exit Room\n";
cout << "3. Inspect the mysterious Statue\n";

int choice = menu(1, 3);
if (choice == 1) return 1;
if (choice == 2) return 4;
    
if (!riddleDone) {
    riddle();
    riddleDone = true;
} else {
    cout << "The statue has nothing more to say.\n";
}
return 2;
}

int room3() {
static bool monsterDefeated = false;
cout << "\n=== Room 3: Monster Lair ===\n";

if (!monsterDefeated) {
    cout << "A monster blocks the path! You must beat him at Nim to pass.\n";
    nim();
    monsterDefeated = true;
    cout << "The monster retreats into the shadows.\n";
} else {
    cout << "The lair is quiet now.\n";
}

showGoldStatus();
cout << "1. Go west  -> Entrance\n";
cout << "2. Go north -> Exit Room\n";

int choice = menu(1, 2);
if (choice == 1) return 1;
return 4;
}

int room4() {
cout << "\n=== Room 4: Exit Room ===\n";
cout << "The exit is right here!\n";
showGoldStatus();

cout << "1. Go back to Treasure Room\n";
cout << "2. Go back to Monster Lair\n";
cout << "3. Exit the building (Finish)\n";

int choice = menu(1, 3);
if (choice == 1) return 2;
if (choice == 2) return 3;
return 0; // Exit loop
}

// --- MAIN LOOP ---

int main() {
int currentRoom = 1;
cout << "==*== ROOM OF GOLD: ADVANCED EDITION ==*==\n";

while (currentRoom != 0) {
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
currentRoom = 0; 
break;
}
}

cout << "\n*****===***** Game Over ******===******\n";
cout << "Final gold collected: " << gold << endl;
if (gold >= 30) cout << "You are legendary!\n";
else cout << "\nYou survived.\n";

return 0;
}