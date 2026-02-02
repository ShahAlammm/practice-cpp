/*
# include <iostream>
using namespace std;

int main() {

    int n;
// for(;;)- non-terminating loop
    for(n=0; n < 10; n++) {

        //n=0;
        //while(n < 10)
    
        {
        cout << "n: " << n << "\n";
        }
    }
    cout << "finished" << endl;
    return 0;
}
*/
//declare variables - no number starts with a digit
//int 1a; // invalid
//int a1; & int _1; // valid


#include <iostream>
using namespace std;

int main() {

    int v1 = 0;
    int v2;

    while(v1 < 3)
    {
        //v2 = 0;
        cout << "v1: " << v1 << "\n";

        while(v2 < 2)
        {
            cout << "  v2: " << v2 << "\n";
            v2 = v2 + 1;
        }
        v1 = v1 + 1;
    }
    cout << "finished" << endl;

    return 0;
}

/* 
Output:-
v1: 0
  v2: 0
  v2: 1
v1: 1
  v2: 0
  v2: 1
v1: 2
  v2: 0
  v2: 1
finished
*/