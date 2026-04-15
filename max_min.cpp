#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    float Avg = (max + min) / 2.0;

    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;
    cout << "Average of max and min: " << Avg << endl;

    return 0;
}