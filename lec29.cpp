# include <iostream>
using namespace std;

class Playa {
private:
    int ID;
    Playa* Next;

    //void Print{printf("ID: %d Next: %p\n", ID, next);}
    Playa(){static int SerNum=128; ID=SerNum++; Next=NULL;}
};

int main() {
Playa* tmp;
Playa* Playas;

Playas=new Playa;

for(int i=0; i<3; i++){
    tmp=new Playa;
    tmp->Next=Playas;
    Playas=tmp;
}

    printf("Printing second pass......\n");
    for(tmp=Playas; tmp!=NULL; tmp=tmp->Next)
       // tmp->Print();   

    printf("finished\n");    
    return 0;
}