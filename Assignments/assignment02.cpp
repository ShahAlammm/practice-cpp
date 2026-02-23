/*
Name: Shah Alam
Section: 12
Assignment #2
Date: 06 February 2026
*/

#include <iostream>
using namespace std;

int main()
{
// Variable declarations
double num1;  // valu type is double , user can put decimal numbers.
double num2;
// int choice;
    
char choice;   // changed from int to char.

/* ==> I try to get input like this: "Enter your choice ( + , - , * , / )". But it doesn't work. So I changed the type of choice from "int" to "char". I spent a lot of time to figure out the problem.
*/

// Program introduction
cout << "Simple Calculator Program" << endl;
cout << endl;

cout << "Choose an operation by entering the symbol: " << endl;
cout << "(+) for Addition" << endl;
cout << "(-) for Subtraction" << endl;
cout << "(*) for Multiplication" << endl;
cout << "(/) for Division" << endl;
cout << endl;

// User inputs for numbers and operation choice
cout << "Enter the first number: ";
cin >> num1;

cout << "Enter the second number: ";
cin >> num2;

cout << "Enter your choice ( + , - , * , / ): "; // this symbol are store as a character. So I changed the type of choice from "int" to "char". user can write choice as a character.
cin >> choice;

cout << endl;

//  calculation based on user's choice
if (choice == '+')
{
cout << "Result: " << num1 + num2 << endl;
}
else if (choice == '-')
{
cout << "Result: " << num1 - num2 << endl;
}
else if (choice == '*')
{
cout << "Result: " << num1 * num2 << endl;
}
else if (choice == '/')
{
if (num2 == 0) // check for division by zero, because division by zero iundefined and will cause a runtime error.
{
cout << "Error: Division by zero is not allowed." << endl;
}
else
{
cout << "Result: " << num1 / num2 << endl;
}
}
else
{
cout << "Invalid operation selected." << endl;
}


cout << "___________End__of__Calculation___________" << endl;
return 0;
}
