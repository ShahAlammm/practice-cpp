#include <iostream>
using namespace std;

class Playa {
public:
    int ID;
    Playa* Next;

  Playa() {
        static int SerNum = 128;
        ID = SerNum++;
        Next = NULL;
    }

    void Print() {
        printf("ID: %d Next: %p\n", ID, Next);
    }
};

int main() {
    Playa* tmp;
    Playa* Playas;

    Playas = new Playa;

    printf("tmp starts at %p\n", tmp);
    tmp->Print();

    delete tmp;

    printf("tmp after delete is %p\n", tmp);
    tmp->Print();

    if (tmp != NULL)
        tmp->Print();

    return 0;

    for (int i = 0; i < 3; i++) {
        tmp = new Playa;
        tmp->Next = Playas;
        Playas = tmp;
    }

    printf("Printing second pass......\n");

    for (tmp = Playas; tmp != NULL; tmp = tmp->Next)
        tmp->Print();

    printf("finished\n");

    return 0;
}