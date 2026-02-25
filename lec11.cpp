#include <iostream>
using namespace std;


struct IntRealPair // class declaration.
{
    // private:
    int IntVal;
    public:
    double RealVal;
};

void PrintArray(int x[], int NumItems) {

    int i;
    cout<< "Print Array start: ";

    cout << "x: " << x << endl;
    for (int i = 0; i < NumItems; i++) {
        cout << "x[i: " << i << "]: " << x[i] << endl;
    }
    cout << "Print Array end." << endl;
}

int main() {


   int i;
   int a[3];
   int y[300];
   IntRealPair Pair0;

Pair0.IntVal = 27;
Pair0.RealVal = 3.1415926;

cout << "Pair0.IntVal: " << Pair0.IntVal << endl;
cout << "Pair0.RealVal: " << Pair0.RealVal << endl;

   for (int i = 0; i < 3; i++) 

  cout<<"a["<< i << "]: "<<a[i]<<endl;

  cout<<"a itself: "<<a<<endl;

    PrintArray(a, 3);
    PrintArray(y, 4);

    cout << "\nfinish....... \n" << endl;
    return 0;

}


