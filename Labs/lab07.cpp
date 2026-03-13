/*
Name: Shah Alam
Section: 12
Assignment: 07 - Bug Fixing
Date: 10 March 2026
*/


#include <iostream>      //  $include
using namespace std;     //  "using namespace standard"

// function to calculate average
double calculateAverage(int count) {   // original function name "code" and missing type
    double number;  // clearer variable name instead of num
    double sum = 0;   // initialize sum to 0 

    // loop to read numbers
    for (int i = 0; i < count; i++) {  // used ; instead of , and declared i
        cout << "Enter number " << i + 1 << ": ";
        cin >> number;  // reading into double instead of int
        sum = sum + number;  // accumulate total correctly
    }

    double average = sum / count;      //calculate average after loop
    return average;      //return outside loop
}

int main() {
    int numberCount;   // better variable name than num
    double result;      // replaced incorrect type "dbl"

    cout << "This program calculates the average of numbers.\n";   // improved message
    cout << "How many numbers do you want to average? ";           // was cout >> 
    cin >> numberCount;    // read count from user

    result = calculateAverage(numberCount);  // pass argument to function

    cout << "\nThe average of your " << numberCount << " numbers is: "; //  proper cout formatting
    cout << result << endl;       // fixed- was "/n/n"

    return 0;   // added: proper program ending
}