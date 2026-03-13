# include <iostream>
using namespace std;

class Widget
{
int SerNum; 
double Width;

public:
double WidthGet() { return Width; }
void WidthSet(double w) { Width = w; }
int SerNumGet() { return SerNum; }
Widget() { static int n = 256; SerNum = n++; Width = 0.0;}
};

int main()
{
Widget w1;
Widget * w2 = new Widget();
Widget * w3 = new Widget();

cout << "w1 ser#: " << w1.SerNumGet() << endl;
cout << "w1 width: " << w1.WidthGet() << endl;

cout << "w2 ser#: " << w2->SerNumGet() << endl;  
cout << "w2 width: " << (*w2).WidthGet() << endl; // w2 -> = (*w2) . SerNumGet()

delete w2;

w2 = &w1; // w2 now points to w1

cout << "w3 ser#: " << w3->SerNumGet() << endl;
cout << "w3 width: " << w3->WidthGet() << endl;


cout << "finished." << endl;
return 0;
}