#include <iostream>
using namespace std;

// Function prototypes
int add(int x, int y);
int SumInRange(int x, int y);

int main() {
    int k, n, sum;

    cout << "Enter the value of k and n: ";
    cin >> k >> n;


    while (k >= n) {
        cout <<"give me a k less than " << n << ": ";
        cin >> k;
    }
    

    sum = add(k, n);
    cout << "The sum of " << k << " and " << n << " is " << sum << endl;

    sum = SumInRange(k, n);
    cout << "SumInRange(" << k << ", " << n << "): " << sum << endl;

    return 0;
}

// Function definitions (outside main)
int add(int x, int y) {
    return x + y;
}

int SumInRange(int x, int y) {
    int sum = 0;
    /*
    if(x >= y) {
        return 0; // Return 0 if x is greater than or equal to y
    }   
    while (x <= y) {
        sum += x;
        x++;
    }
    */
   if(x < y) {
       while (x <= y) {
           sum += x;
           x++;
       }
   }
   return sum;
}
