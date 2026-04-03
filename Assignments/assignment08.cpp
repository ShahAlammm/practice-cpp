/*
Name: Shah Alam
Assignment: 08
Section: 12
Date: 24 March 2026
*/

#include <iostream>
#include <cstdlib>   // only this for random
using namespace std;

// generate random numbers, i use a library .
void generate(double a[], int n, double low, double high) {
    for(int i = 0; i < n; i++) {
        double r = (double)rand() / RAND_MAX; 
        a[i] = low + r * (high - low);
    }
}

//for print array
void print(double a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// average of array
double average(double a[], int n) {
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

// minimum value
double min(double a[], int n) {
    double m = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] < m)
            m = a[i];
    }
    return m;
}

// maximum
double max(double a[], int n) {
    double m = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] > m)
            m = a[i];
    }
    return m;
}

// add value
void addX(double a[], int n, double x) {
    for(int i = 0; i < n; i++) {
        a[i] = a[i] + x;
    }
}

// less than average
int num_less_avg(double a[], int n) {
    double avg = average(a, n);
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] < avg)
            count++;
    }
    return count;
}

// range
double range(double a[], int n) {
    double maxVal = a[0];
    double minVal = a[0];

    for(int i = 1; i < n; i++) {
        if(a[i] > maxVal)
            maxVal = a[i];
        if(a[i] < minVal)
            minVal = a[i];
    }

    return maxVal - minVal;
}



// -------- main function here--------
int main() {
    int size = 10;
    double data[10];

    generate(data, size, -5, 5);

    cout << "Array: ";
    print(data, size);

    cout << "Average: " << average(data, size) << endl;
    cout << "Min: " << min(data, size) << endl;
    cout << "Max: " << max(data, size) << endl;
    cout << "Range: " << range(data, size) << endl;

    cout << "Less than avg: " << num_less_avg(data, size) << endl;

    addX(data, size, 2);
    cout << "After adding 2: ";
    print(data, size);

    
    
    return 0;
}
//  num_more(), num_less(), std_dev not done.