/*
Name: Shah Alam
Section: 12
Assignment #2 (Modified for Lab)
Date: 06 February 2026
*/

#include <iostream>
using namespace std;

int main()
{
double num1, num2;
char choice;
char again;   // for repeating the program

cout << "Simple Calculator Program" << endl;
cout << endl;

do  // Loop for verifying the user wants to perform another calculation
{
cout << "Choose an operation by entering the symbol: " << endl;
cout << "(+) for Addition" << endl;
cout << "(-) for Subtraction" << endl;
cout << "(*) for Multiplication" << endl;
cout << "(/) for Division" << endl;
cout << "(s) for Sum of integers between the two numbers" << endl;
cout << endl;

cout << "Enter the first number: "; // input 
cin >> num1;

cout << "Enter the second number: ";  //input 
cin >> num2;

        // Loop for verifying the user input is * valid * for the operation choice
do
{
cout << "Enter your choice ( + , - , * , / , s ): "; //input
cin >> choice;
// check the input is valid or not.
if (choice != '+' && choice != '-' && choice != '*' &&
choice != '/' && choice != 's')
{
cout << "Error: Invalid operation. Please try again." << endl;
}

} while (choice != '+' && choice != '-' && choice != '*' && choice != '/' && choice != 's');

cout << endl;

        // Perform calculation here
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
if (num2 == 0)  // num2 is denominator and it should not be zero. 
{
cout << "Error: Division by zero is not allowed." << endl;
}
else
{
cout << "Result: " << num1 / num2 << endl;
}
}
else if (choice == 's')
{
            // Truncate double to int
int new_num1 = num1;
int new_num2 = num2;

            // check sure new_num1 is smaller than new_num2
if (new_num1 > new_num2)
{
int temp = new_num1;
new_num1 = new_num2;
new_num2 = temp;
}

int sum = 0;

for (int i = new_num1; i <= new_num2; i++)
{
sum += i;
}

cout << "Sum of integers between " << new_num1 << " and " << new_num2 << " is: " << sum << endl;
}

cout << endl;
cout << "Do you want to perform another calculation? (y/n): ";
cin >> again;
cout << endl;

} while (again == 'y' || again == 'Y');

cout << "___________new_num2__of__Program___________" << endl;

return 0;
}
