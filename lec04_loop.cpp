 /*# include <iostream>
using namespace std;

int main() {
    int v1;


    cout << "Enter value > 0 for V1: ";
    
    cin >> v1;

    while(v1 < 0)
    {
        cout <<"Enter positive value > 0 for V1: ";
        cin >> v1;

    }

    cout << "finished.\n";



    return 0;
}
    */
/*--------------------------------------------------------------*/

#include <iostream>
using namespace std;

int main() {
    int month;


    cout << "Enter the number of a month (1-12): ";
    cin >> month;

    while(month <= 0 || month >= 13) /*while(month > 0 && month < 13) / while(!(month > 0 && month < 13))*/
    {
        cout <<"Enter the number of a month (1-12): ";
        cin >> month;

    }

    //do
    //{
        /* code */
    //} while (condition);
    

    cout << "finished.\n";

    return 0;
}
    
