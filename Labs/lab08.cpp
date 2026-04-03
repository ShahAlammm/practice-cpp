/*
Name: Shah Alam
Section: 12
Lab: 08
Date: 24 March 2026
*/


#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream infile;
    infile.open("weather.txt");

    if (!infile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    // Skip header line
    string header;
    getline(infile, header);

    const int SIZE = 31;

    int day, year;
    string month;

    double high[SIZE], low[SIZE], precip, snow, snowDepth[SIZE];

    // Read data
    for (int i = 0; i < SIZE; i++) {
        infile >> day >> month >> year;
        infile >> high[i] >> low[i];
        infile >> precip >> snow >> snowDepth[i];
    }


    // Let finding values
    double maxTemp = high[0];
    double minTemp = low[0];
    double sumHigh = 0;
    double sumLow = 0;
    double snowChangeSum = 0;

    // Calculations
    for (int i = 0; i < SIZE; i++) {
        if (high[i] > maxTemp)
            maxTemp = high[i];

        if (low[i] < minTemp)
            minTemp = low[i];

        sumHigh += high[i];
        sumLow += low[i];

        if (i > 0) {
            snowChangeSum += (snowDepth[i] - snowDepth[i - 1]);
        }
    }

    double avgHigh = sumHigh / SIZE;
    double avgLow = sumLow / SIZE;
    double avgSnowChange = snowChangeSum / (SIZE - 1);

    // Output results
    cout << "\nHighest Temperature: " << maxTemp << " F" << endl;
    cout << "Lowest Temperature: " << minTemp << " F" << endl;
    cout << "Average High Temperature: " << avgHigh << " F" << endl;
    cout << "Average Low Temperature: " << avgLow << " F" << endl;
    cout << "Average Daily Snow Depth Change: " << avgSnowChange << " inches\n" << endl;
    
    cout << "finished....." << endl;
    return 0;
}