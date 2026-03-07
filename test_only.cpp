#include <iostream>
#include <cmath>
using namespace std;

class Rectangle {
private:
    int width;
    int height;
    
public:
    // Constructor that sets width and height to 0
    Rectangle() {
        width = 0;
        height = 0;
    }
    
    // Function to set width and height with positive value enforcement
    void setDimensions(int w, int h) {
        // Make width positive if negative
        if (w < 0) {
            width = -w;
        } else {
            width = w;
        }
        
        // Make height positive if negative
        if (h < 0) {
            height = -h;
        } else {
            height = h;
        }
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
    
    // Create first rectangle - test with positive values
    cout << "Test 1: Rectangle with positive values (5, 3)" << endl;
    Rectangle rect1;
    rect1.setDimensions(5, 3);
    rect1.print();
    cout << "Area: " << rect1.area() << endl;
    cout << "Perimeter: " << rect1.perimeter() << endl << endl;
    
    // Create second rectangle - test with negative values
    cout << "Test 2: Rectangle with negative values (-4, 6)" << endl;
    Rectangle rect2;
    rect2.setDimensions(-4, 6);
    rect2.print();
    cout << "Area: " << rect2.area() << endl;
    cout << "Perimeter: " << rect2.perimeter() << endl << endl;
    
    // Create third rectangle - test with zero and negative values
    cout << "Test 3: Rectangle with zero and negative (0, -8)" << endl;
    Rectangle rect3;
    rect3.setDimensions(0, -8);
    rect3.print();
    cout << "Area: " << rect3.area() << endl;
    cout << "Perimeter: " << rect3.perimeter() << endl << endl;
    
    // Test the constructor initializing to zero
    cout << "Test 4: Default constructor (should be all zeros)" << endl;
    Rectangle rect4;
    rect4.print();
    cout << "Area: " << rect4.area() << endl;
    cout << "Perimeter: " << rect4.perimeter() << endl;
    
    return 0;
}