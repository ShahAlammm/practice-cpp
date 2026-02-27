/*
Name: Shah Alam
Section: 12
Lab: Lab 5 - Pass by Reference
Date: February 24, 2026

*/

#include<iostream>
using namespace std;

// using pass-by-reference: & symbols
void flip(int &a, int &b);

int main(){
int x = 7;
int y = 20;
    
cout << "\nBefore flip: x = " << x << ", y = " << y << endl;

flip(x, y);  // call the flip function, pass values.

cout << "\nAfter flip:  x = " << x << ", y = " << y << endl;

cout << "\nfinished.... \n" << endl;
return 0;
}

//  passes by reference function.
void flip(int &a, int &b){
int temp = a;  // store the value of a in a temporary variable
a = b;         // change a's value to b
b = temp;      // assign the a's value (stored in temp) to b
}