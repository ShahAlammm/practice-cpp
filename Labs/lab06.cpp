/*
Name: Shah Alam
Section: 12
Lab: 06
Date: 3 March 2026
*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// declaration of the pet class
class pet{
private:
    int hunger; // private data member
    string name; // private data member
    int happy; // private data member
    int energy;   // ---> NEW data member

public:
    pet();
    void play(); // constructor
    void feed();// public member function
    void nap();   // ---> NEW function
    void print();// public member function
    int check_health();// public member function
};

int main()
{
    srand(time(0));   // sets a different random starting point for the random number generator each time the program is run.

    pet pet1;
    int choice;
    int health_check;

    do{
        pet1.print();

        cout << "\nWhat would you like to do with your pet?\n";
        cout << "Play (1)\nFeed (2)\nNap (3)\nExit (0)\n";

        cin >> choice;

        switch(choice){

        case 1:
            pet1.play();
            break;

        case 2:
            pet1.feed();
            break;

        case 3:
            pet1.nap();
            break;

        case 0:
            cout << "\nGoodbye! Take care of your pet next time!\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

        health_check = pet1.check_health(); // check health after each action here.

    }while(choice != 0 && health_check != 1);

    cin.ignore();
    cout << "Press enter to exit." << endl;
    cin.ignore();

    return 0;
}


/* Constructor, creates a new pet with starting values. */
pet::pet(){
    hunger = 50;
    happy = 50;
    energy = 50;

    cout << "Pet's name? (One word) ";
    cin >> name;
}


/* Member function play(), allows playing with a pet. */
void pet::play(){
    int choice = 0;

    cout << "What should we play?\n";
    cout << "Fetch (1)\nRoll over (2)\n";

    cin >> choice;

    switch(choice){

    case 1:
        cout << name << " loves playing fetch!\n";
        happy += 10;
        hunger += 5;
        energy -= 5;
        break;

    case 2:
        cout << name << " rolls over happily!\n";
        happy += 5;
        hunger += 2;
        energy -= 3;
        break;

    default:
        cout << "Not a valid choice.\n";
    }
}


/* Member function feed(), allows the user to feed a pet. */
void pet::feed(){

    int r = rand() % 3; // generates a random number 0–2 to determine the pet's reaction to being fed.

    if(r == 0)
        cout << name << " says: Yum! That was tasty!\n";
    else if(r == 1)
        cout << name << " happily eats the food!\n";
    else
        cout << name << " says: More food please!\n";

    hunger -= 10;
    energy += 5;
}


/* NEW Member function nap(), allows a pet to take a nap. */
void pet::nap(){
    cout << name << " is taking a nap...Z .Z .Z\n";

    energy += 15;
    hunger += 5;
    happy += 2;
}


/* Member function print(), prints information about a pet. */
void pet::print(){

    cout << "\nYour pet " << name << endl;

    cout << "Happiness: " << happy << endl;
    cout << "Hunger: " << hunger << endl;
    cout << "Energy: " << energy << endl;

    // happiness messages
    if(happy >= 80)
        cout << name << " is extremely happy!\n";
    else if(happy >= 60)
        cout << name << " is feeling good.\n";
    else if(happy >= 40)
        cout << name << " is okay.\n";
    else
        cout << name << " looks sad.\n";

    // hunger messages
    if(hunger >= 80)
        cout << name << " says: I'm starving!\n";
    else if(hunger >= 60)
        cout << name << " says: I'm very hungry.\n";
    else if(hunger >= 40)
        cout << name << " could eat something.\n";
    else
        cout << name << " is full.\n";
}


/* Member function check_health(), checks the health of a pet. */
int pet::check_health(){

    if(hunger >= 100){
        cout << "\nYour pet has starved.\n";
        return 1;
    }

    if(happy <= 0){
        cout << "\nYour pet has died of a broken heart.\n";
        return 1;
    }

    return 0;
}