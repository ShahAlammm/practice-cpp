/*
Name: Shah Alam
Section: 12
Assignment: 06 - Rectangle Class
Date: 3 March 2026
*/

#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int height;

public:
// Constructor for set width and height to 0
    Rectangle() {
        width = 0;
        height = 0;
    }

// for set width and height to positive values
void setSize(int w, int h) {
    if (w < 0)
        w = -w;
    if (h < 0)
        h = -h;

    width = w;
    height = h;
}

// Print function
void print() {
        cout << "width = " << width << endl;
        cout << "height = " << height << endl;
    }

    // Area function
    int area() {
        return width * height;
    }

    // Perimeter function
    int perimeter() {
        return 2 * (width + height);
    }
};

int main() {

cout << "Rectangle Class Test Program" << endl;
cout << "=============================" << endl << endl;

// Create rectangle objects for testing.
Rectangle r1;
Rectangle r2;
Rectangle r3;
Rectangle r4; // for default constructor test


// Set sizes
r1.setSize(5, 10);
r2.setSize(-8, 4);   // negative value test
r3.setSize(0, 12);   // zero test

//  Rectangle 1
cout << "Rectangle 1:" << endl;
r1.print();
cout << "Area = " << r1.area() << endl;
cout << "Perimeter = " << r1.perimeter() << endl;
cout << endl;

//  Rectangle 2
cout << "Rectangle 2:" << endl;
r2.print();
cout << "Area = " << r2.area() << endl;
cout << "Perimeter = " << r2.perimeter() << endl;
cout << endl;

//  Rectangle 3
cout << "Rectangle 3:" << endl;
r3.print();
cout << "Area = " << r3.area() << endl;
cout << "Perimeter = " << r3.perimeter() << endl;

//  Rectangle 4 - default constructor test.
cout << "\nTest 4: Default constructor (should be all zeros)" << endl;
    
r4.print();
cout << "Area: " << r4.area() << endl;
cout << "Perimeter: " << r4.perimeter() << endl;

cout << "\nFinished all tests...." << endl;

return 0;
}