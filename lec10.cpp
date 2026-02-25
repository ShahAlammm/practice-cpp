# include <iostream>
using namespace std;


int main() {
    
    int i;
    int a[3];


    for (i = 0; i < 1048576; i++) {

        cout << "\na[" << i << "]: "<< a[i] << endl;
       
    }
    

    

    cout << "\nfinished." << endl;
    return 0;
}



int old_main() {
    
    int n;

    cout<< "\nenter n: ";
    cin >> n;

/*
   switch (n)
    {
        case 1:
            cout << "\nn is 1." << endl;
            break;
        case 5:
            cout << "\nn is 5." << endl;
            break;
        default:
            cout << "\nn is something else." << endl;
            break;
    }  
*/

switch (n)
{
case 1:
case 3:
case 5:
case 7:
case 9:
     cout << "\nn is even." << endl;
    break;
case 0:
case 2:
case 4:
case 6:
case 8:
     cout << "\nn is odd." << endl;
default:
    break;
}

    cout << "\nfinished." << endl;
    return 0;
}