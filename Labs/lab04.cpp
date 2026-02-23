/* Name: Shah Alam
Section: 12
Lab: Lab 4 - Extended Calculator
Date: February 17, 2026
*/

#include <iostream>

using namespace std;


const double PI = 3.14159;  // Global constant for pi, its not change .

//---------- Function Prototypes -----------
void print_menu();
double get_value();
double divide(double, double);
double cylinder_surface_area(double, double);
double cylinder_volume(double, double);
double cone_surface_area(double, double);

//-------------- Main -------------------
int main() {
double operand1, operand2, answer;
int choice, valid_choice;

do {
print_menu();
cin >> choice;

        
valid_choice = 1;

//  0 for 'Exit' so it doesn't print a final answer
valid_choice = 1; 

switch (choice) {
case 0: // Exit
valid_choice = 0; 
cout << "Exit program ----" << endl;
break;
case 1: // Addition
operand1 = get_value();
operand2 = get_value();
answer = operand1 + operand2;
cout << endl << operand1 << " + " << operand2 << " = " << answer <<endl;
break;
case 2: // Subtraction
operand1 = get_value();
operand2 = get_value();
answer = operand1 - operand2;
cout << endl << operand1 << " - " << operand2 << " = " << answer <<endl;
break;
case 3: // Division
operand1 = get_value();
operand2 = get_value();
answer = divide(operand1, operand2);
cout << endl << operand1 << " / " << operand2 << " = " << answer <<endl;
break;
case 4: // Cylinder Surface Area
operand1 = get_value(); // radius
operand2 = get_value(); // height
answer = cylinder_surface_area(operand1, operand2);
cout << endl << "Cylinder surface area (r= " << operand1 << ", h= "<< operand2 << ") = " << answer << endl;
break;
case 5: // Cylinder Volume
operand1 = get_value(); // radius
operand2 = get_value(); // height
answer = cylinder_volume(operand1, operand2);
cout << endl << "Cylinder volume (r= " << operand1 << ", h= " <<operand2 << ") = " << answer << endl;
break;
case 6: // Cone Surface Area
operand1 = get_value(); // radius
operand2 = get_value(); // height
answer = cone_surface_area(operand1, operand2);
cout << endl << "Cone surface area (r= " << operand1 << ", h= " <<operand2 << ") = " << answer << endl;
break;
default:
valid_choice = 0;
cout << "Invalid Choice." << endl;
}


} while (choice != 0);

return 0;
}

//--------------All Functions -------------------> not in main()


// divide 

double divide(double dividend, double divisor) {
if (divisor == 0) {
cout << "Error: Division by zero! ";
return 0;
}
return (dividend / divisor);
}


// Cylinder surface area = 2πr^2 + 2πrh
double cylinder_surface_area(double r, double h) {
return (2 * PI * r * r) + (2 * PI * r * h);
}

// Cylinder volume = πr^2h
double cylinder_volume(double r, double h) {
return PI * r * r * h;
}

// Cone surface area = πr(r + sqrt(h^2 + r^2))
double cone_surface_area(double r, double h) {
return PI * r * (r + sqrt((h * h) + (r * r)));
}

double get_value() {
double temp_value;
cout << "Please, enter a value: ";
cin >> temp_value;
return temp_value;
}

void print_menu() {
cout << "\n---- Calculator Menu ----" << endl;
cout << "1. Add" << endl;
cout << "2. Subtract" << endl;
cout << "3. Divide" << endl;
cout << "4. Cylinder Surface Area" << endl;
cout << "5. Cylinder Volume" << endl;
cout << "6. Cone Surface Area" << endl;
cout << "0. Exit" << endl;
cout << "Enter your choice: ";
}