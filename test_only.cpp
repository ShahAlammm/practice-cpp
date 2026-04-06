#include <iostream>
using namespace std;

int main() {


    int A[3][4];

    // Initialize the array
    
    /*for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            A[i][j] = i * j;
        }
    }
*/
    // Print the array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}