#include <iostream>
using namespace std;


class IntRealPair {
public:
    int ival;
    double rval;
};

int main() {
    IntRealPair * p1 = NULL; // pointer to IntRealPair, initialized to NULL
    IntRealPair * p2; // dynamically allocated instance of 

    cout << "p1: " << p1 << endl; // prints the value of p1 (NULL)
    cout << "p2: " << p2 << endl; // prints the value of p2 (address of the allocated memory)

    cout << "*p1: "<< p1->ival << endl; // dereferencing p1 will cause a runtime error (segmentation fault) because p1 is NULL
    cout << "*p2: "<< p2->ival << endl; // dereferencing p2 will print the default values of ival and rval (garbage values) because p2 is allocated but not initialized

    cout << "finished" << endl;
}
