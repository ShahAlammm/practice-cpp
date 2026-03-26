#include <iostream>
using namespace std;

void SwapVals(int & v1, int & v2)
{
    int tmp;

    cout << "SwapVals: begin: v1: " << v1 << " v2: " << v2 << endl;

    tmp = v1;
    v1 = v2;
    v2 = tmp;

    cout << "SwapVals: done: v1: " << v1 << " v2: " << v2 << endl;
}

int main()
{
    int * p;
    int a, b;

    cout << "enter two ints: ";
    cin >> a >> b;

    cout << "start: a: " << a << " b: " << b << endl;

    p = &a;
    cout << "a address: " << &a << endl;
    cout << "p value: " << p << endl;
    cout << "value that p points to: " << *p << endl;
    
    cout << "finished." << endl;
    return 0;
}

int old_main()
{
    int x, y;
    
    cout << "enter two ints: ";
    cin >> x >> y;

    cout << "before swap: x: " << x << " y: " << y << endl;
    
    SwapVals(x, y);

    cout << "after swap: x: " << x << " y: " << y << endl;

    cout << "finished." << endl;
    return 0;
}
