#include <iostream>
using namespace std;

int main() {

    int v1, v2;

    cout << "enter values for v1 and v2: " << endl;
    cin >> v1 >> v2;

    cout << "v1:" << v1 << ", v2:" << v2 << endl;

    /*if (v1 == v2) {
    cout << "v1 and v2 are equivalent." << endl;
    } else {
    cout << "v1 and v2 are not equivalent." << endl;
    }*/

    if (v1 && v2) {
        cout << "They are both non-zero." << endl;
    } else if (v1 || v2) {
        cout << "one of v1 or v2 is non-zero." << endl;
    } else {
        cout << "Both v1 and v2 are zero." << endl;
    }   

    cout << "End of program." << endl;
    
    return 0;
}