/*

#include <iostream>
using namespace std;

int main() {
    int n;
    n=0 ;

    // A while loop may run zero times if the condition is false at the start. 
    while(n < 5) {    //(n > 5) No value will be printed since the condition is false at the beginning.
        n = n + 1;
        cout << "n: " << n << "\n";
        
    }

    cout <<"*************************" << endl;
    n = 0;

    // A do-while loop always runs at least 'once', even if the condition is false initially.
    do {
        n = n + 1;
        cout << "n: " << n << "\n";
        
    } while(n < 5);
    

    cout << "finished.\n";

    return 0;
}
*/
/*--------------------------------------------------------------*/

/*
    # include <iostream>
    using namespace std;

    int main() {
        int n;
        n=0 ;

        while(n < 5) {    
            //n = n + 1;
            //  increase n by 1 using post-increment(n++) operator / pre-increment(++n) operator [for n++, n + 1 && ++n means 1 + n]

            cout << "n: " << ++n << "\n";
            
        }

        return 0;
    }
*/
    /*
    2 + 3 // infix notation
    +(2, 3) // prefix notation
    (2, 3)+ // postfix notation
    */

/*--------------------------------------------------------------*/
/*
# include <iostream>
using namespace std;        

int main() {

    int n;
    int k;

    n = 0;
    k = 3;
//  Increment n by 3 using compound assignment operator (+=), (-=), (*=), (/=)
    while(n < 10) {    
{
    cout << "n: " << n << endl;
    k -= 3; k = -3;
    n /= k;
}
        
    }

    return 0;
}
*/
/*--------------------------------------------------------------*/

    # include <iostream>
    using namespace std;

    int main() {

        int n;
        n = 0;

        while(n < 10) {
            {
            cout << "n: " << n << "\n";
            n++;
            }
        }

        cout << "************************" << endl; 

        
        for(n=0; n < 10; n++) {
            cout << "n: " << n << "\n";
        }


        return 0;
    }