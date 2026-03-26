/*
Name: Shah Alam
Assignment: 07
Section: 12
Date: 13 March 2026
*/


#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:

    // function to set fraction
    void setFraction(int n, int d)
    {
        if (d == 0)
        {
            numerator = 0;
            denominator = 1;
        }
        else
        {
            numerator = n;
            denominator = d;
        }
    }

    // print improper fraction
    void printImproper()
    {
        cout << numerator << "/" << denominator << endl;
    }

    // print mixed number
    void printMixed()
    {
        int whole = numerator / denominator;
        int remainder = numerator % denominator;

        cout << whole << " " << remainder << "/" << denominator << endl;
    }

    // print decimal
    void printDecimal()
    {
        double decimal = (double)numerator / denominator;
        cout << decimal << endl;
    }

    // add fractions
    Fraction add(Fraction f)
    {
        Fraction result;
        result.numerator = numerator * f.denominator + f.numerator * denominator;
        result.denominator = denominator * f.denominator;
        return result;
    }

    // subtract
    Fraction subtract(Fraction f)
    {
        Fraction result;
        result.numerator = numerator * f.denominator - f.numerator * denominator;
        result.denominator = denominator * f.denominator;
        return result;
    }

    // multiply
    Fraction multiply(Fraction f)
    {
        Fraction result;
        result.numerator = numerator * f.numerator;
        result.denominator = denominator * f.denominator;
        return result;
    }

    // divide
    Fraction divide(Fraction f)
    {
        Fraction result;
        result.numerator = numerator * f.denominator;
        result.denominator = denominator * f.numerator;
        return result;
    }
};


// main function .
int main()
{
    Fraction fun1, fun2, fun3, result;

    fun1.setFraction(6,4);
    fun2.setFraction(3,5);
    fun3.setFraction(7,0);

    cout << "Fraction 1:" << endl;
    fun1.printImproper();
    fun1.printMixed();
    fun1.printDecimal();

    cout << endl;

    cout << "Fraction 2:" << endl;
    fun2.printImproper();
    fun2.printMixed();
    fun2.printDecimal();

    cout << endl;

    cout << "Fraction 3:" << endl;
    fun3.printImproper();
    fun3.printMixed();
    fun3.printDecimal();

    cout << "Addition (fun1 + fun2): ";
    result = fun1.add(fun2);
    result.printImproper();

    cout << "Subtraction (fun1 - fun2): ";
    result = fun1.subtract(fun2);
    result.printImproper();

    cout << "Multiplication (fun1 * fun2): ";
    result = fun1.multiply(fun2);
    result.printImproper();

    cout << "Division (fun1 / fun2): ";
    result = fun1.divide(fun2);
    result.printImproper();

    cout << "\nFinished....."  << endl;

    return 0;
}