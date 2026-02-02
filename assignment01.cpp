//Name: Shah Alam
//Section: M
//Assignment 01!
//Date: 30 January 2026

/* The fortune Teller -
* a simple program introducing some
* fundamental programming concepts.
*/
#include<iostream> // include a library
using namespace std;
int main() // main() starts the program
{
// -------------- Variable Declarations ------------------
int favorite; // create a variable to store the favorite number
int disliked; // create a variable to store the disliked number
int lucky; // create a variable to store the lucky number
int apartment_number; // create a variable to store apartment number
// ------------- Get user input -------------------------
//I will add apartment number!
cout<<"Enter your apartment number (no decimals): ";//output
cin>>apartment_number;//user input

cout << "Enter your favorite number (no decimals): "; // output
cin >> favorite; // user input

cout << "Enter a number you don't like (no decimals): "; //output
cin >> disliked;//input
// ------------- Calculate lucky number -----------------
lucky = (apartment_number*favorite*disliked) % 10;
// ------------- Output lucky number and message --------
cout << endl << "Your secret, lucky number is: " << lucky << endl;
if(lucky < 0){ // conditional, values less than 0
cout << "Try to be less negative." << endl;
}
if(lucky >= 0 && lucky < 5){ // values 0 to 4 inclusive
cout << "Think bigger!" << endl;
}
if(lucky >= 5 && lucky < 9){ // values 5 to 8 inclusive
cout << "Today you should embrace technology." << endl;
}
if(lucky == 9){ // value exactly 9
cout << "Today is your lucky day!" << endl;
}
// New conditional message for when the lucky number exactly 3 is!
if (lucky == 3) {
cout << "A surprise is waiting for you soon!" << endl;
}
// ---------- Code to help the program exit "gracefully" -----
cin.ignore();
cout << "Press enter to quit." << endl;
cin.ignore();

return 0;
}
