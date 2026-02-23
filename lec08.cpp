#include <iostream>
using namespace std;


int add(int x, int y); // Declaration of the function add
// Function prototype: it tells the compiler about the function name, return type, and parameters. It allows us to call the function before its definition in the code.
 void func(int, float); // function prototype with unnamed parameters

int main()
{
    //int result = add(5, 10);
    //cout << "The sum is: " << result << endl;

    int k, n, sum;

    cout << "Enter k and n: ";
    cin >> k >> n;

    cout << "k: " << k << ", n: " << n << endl;
    sum = add(k, n);
    cout << "The sum is: " << sum << endl;
    cout << "k: " << k << ", n: " << n << endl;

    func(k, (float)n); // implicit type conversion from int to float

    cout << "finished" << endl;

    return 0;
}

// Definition of the function add
int add(int x, int y) {
    return x + y;
}

void func(int x, float y) {
    cout<<"func: x: " << x << ", y: " << y << endl;
}