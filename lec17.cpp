#include <iostream>
using namespace std;

void SwapValsRefs(int & v1, int & v2)
{
    int tmp;

    cout << "SwapValsRefs: begin: v1: " << v1 << " v2: " << v2 << endl;

    tmp = v1;
    v1 = v2;
    v2 = tmp;

    cout << "SwapValsRefs: done: v1: " << v1 << " v2: " << v2 << endl;
}

void SwapValsPtrs(int * v1, int * v2)
{
    int tmp;

    cout << "SwapValsPtrs: begin: v1: " << *v1 << " v2: " << *v2 << endl;

    tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;

    cout << "SwapValsPtrs: done: v1: " << *v1 << " v2: " << *v2 << endl;
}

int main()
{
    int a, b;

    cout << "enter two ints: ";
    cin >> a >> b;

    cout << "in main start: a: " << a << " b: " << b << endl;

    // SwapValsRefs(a, b);

    SwapValsPtrs(&a, &b);
    
    cout << "in main after Swap: a: " << a << " b: " << b << endl;

    
    cout << "finished." << endl;
    return 0;
}


