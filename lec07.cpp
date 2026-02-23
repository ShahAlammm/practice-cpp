
# include <iostream>
using namespace std;

int main() {

    int n;

    for(int i = 1; i < 3; i++) 
    /*{

        for(int n = 5+i; n > 0; n--) {
            cout << "* ";
            cout << endl;
        }
        cout << "i = " << i << endl;
    }*/
    {
        n = 5 + i;
        while (n > 0) {         // we cannot use variable in while condition
            int i = 3;
            cout << "* " << i << endl;
            n--;
        }
        cout << endl;
    }
    cout << "finished" << endl;
}