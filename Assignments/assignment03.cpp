/*
Name: Shah Alam
Section: 12
Assignment #3
Date: 11 February 2026
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
const int START_OBJECTS = 23;
const int MIN_MOVE = 1;
const int MAX_MOVE = 3;

char playAgain;

do   // play multiple games
{
int num_objects = START_OBJECTS;
int current_player = 1;
int move;

cout << "---------Welcome to the Game of NIM---------"<< endl;
cout << "There are " << START_OBJECTS << " objects." << endl;
cout << "Each player can remove 1 to 3 objects." << endl;
cout << "Whoever removes the last object wins." << endl;

do   // main game loop
{
// display the current state of the game
cout << "\nObjects remaining: ";
for (int i = 0; i < num_objects; i++)
{
cout << "*";
}
cout << " (" << num_objects << ")" << endl;

// remind players how the game is going
if (num_objects > 15)
cout << "It is still early in the game." << endl;
else if (num_objects > 5)
cout << "The game is getting serious!" << endl;
else
cout << "Very close to the end!" << endl;

if (current_player == 1)
{
cout << "Player 1, enter your move (1-3): ";
cin >> move;

while (move < MIN_MOVE || move > MAX_MOVE || move > num_objects)
{
cout << "Invalid move. Try again: ";
cin >> move;
}
}
else
{
     // computer move from here
     
if (num_objects == 2)
    move = 1;
else if (num_objects == 3)
    move = 2;
else if (num_objects == 4)
    move = 3;
else
{
move = rand() % MAX_MOVE + 1;
while (move > num_objects)
    move = rand() % MAX_MOVE + 1;
}

cout << "Computer removes " << move << endl;
}

num_objects = num_objects - move;

current_player = (current_player + 1) % 2;

} while (num_objects > 0);   // game continues

cout << "Player " << current_player << " wins!" << endl;

cout << "Play again? (y/n): ";
cin >> playAgain;

} while (playAgain == 'y' || playAgain == 'Y');

cout << "Thanks for playing!" << endl;

return 0;
}
