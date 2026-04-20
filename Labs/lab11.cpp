#include <iostream>
using namespace std;

int factorial(int);

int main()
{
cout << "The factorial of 5 is: " << factorial(5) << endl;
return 0;
}

int factorial(int n)
{
if (n <= 1)
return 1;
else
return n * factorial(n-1);
}