#include <iostream>
using namespace std;


class IntRealPair {
public:
    int ival;
    double rval;
};

int main() {
    IntRealPair * p1 = NULL; // pointer to IntRealPair, initialized to NULL
    IntRealPair * p2 = NULL; // dynamically allocated instance of IntRealPair

    cout << "p1: " << p1 << endl; // prints the value of p1 (NULL)
    cout << "p2: " << p2 << endl; // prints the value of p2 (NULL)

    p1 = new IntRealPair; // dynamically allocate memory for an IntRealPair and assign its address to p1
    p2 = new IntRealPair[128]; // dynamically allocate memory for another IntRealPair and assign its address to p2

    cout << "p1->ival: "<< p1->ival << endl; // dereferencing p1 will cause a runtime error (segmentation fault) because p1 is NULL
    //cout << "p2->ival: "<< p2->ival << endl; // dereferencing p2 will print the default values of ival and rval (garbage values) because p2 is allocated but not initialized
    //cout << "p2->ival: "<< p2->ival << endl; // dereferencing p2 will print the default values of ival and rval (garbage values) because p2 is allocated but not initialized

    cout << "finished" << endl;
}
