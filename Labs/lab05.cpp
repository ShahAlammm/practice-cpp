#include<iostream>
using namespace std;

void function1(int);
void function2(int &);
void flip(int &);

int main(){

int x = 7;
cout << "x = " << x << endl;

function1(x);
cout << "x = " << x << endl;

function2(x);
cout << "x = " << x << endl;
}

void function1(int z){
z = 2 * z;

}

void function2(int &z){
z = 2 * z;

}
