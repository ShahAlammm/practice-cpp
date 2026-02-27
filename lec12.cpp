#include <iostream>
using namespace std;
 

class IntRealPair
{
private:
    int IntVal;
    double RealVal;
public:
    IntRealPair() { IntVal = 23; RealVal = 1.384; }
    int IntValGet() { return IntVal; }
    void IntValSet(int x) { IntVal = x; }
    double RealValGet() { return RealVal; }
    void RealValSet(double x) { RealVal = x; }
};

int main() {
    int i;
    IntRealPair Pair0;
    IntRealPair Pair1;
    IntRealPair PairArray[8];

    //Pair0.IntValSet(27);
    //Pair0.RealValSet(3.14);

    cout << "Integer Value: " << Pair0.IntValGet() << endl;
    cout << "Real Value: " << Pair0.RealValGet() << endl;

    cout << "Integer Value: " << Pair1.IntValGet() << endl;
    cout << "Real Value: " << Pair1.RealValGet() << endl;


    for (i = 0; i < 8; i++) 
    {
        cout << "PairArray[" << i << "].IntVal: " << PairArray[i].IntValGet() << endl;
        cout << "PairArray[" << i << "].RealVal: " << PairArray[i].RealValGet() << endl;
    }

    return 0;
}

/*
IntRealPair::IntRealPair() {
    return IntVal;
}

double IntRealPair::RealValGet() {
    return RealVal;
}
*/