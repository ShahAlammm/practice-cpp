# include <iostream>
using namespace std;



struct VidyaGame
{
    int year;
    string title;
    double price;
};


void VidyaGamesPrint(VidyaGame a[], int NumGames)
{
    int i;
    cout << "\nThe Vidya Gamezz: " << endl;
    for (i = 0; i < NumGames; i++)
    {
        cout << "\nyear: " << a[i].year << endl;
        cout << "title: " << a[i].title << endl;
        cout << "$ " << a[i].price << endl;
    }

}

void VidyaGamesHighestPrice(VidyaGame a[], int GameCount, double & HighestPrice)
{
    int i;
    double NewHigh;

    NewHigh = a[0].price;

    for (i=1; i < GameCount; i++)
    {
        if (a[i].price > NewHigh)
        {
            NewHigh = a[i].price;
        }

    }

    HighestPrice = NewHigh;
}

// #### Main Function :-

int main() {

// pointers: it is a variable that holds the memory address of another variable.
    int idx;
    double f;
    VidyaGame lib[8];

    for (idx = 0; idx < 2; idx++)
    {
        cout << "Enter the year, title and price of the game: ";
        cin >> lib[idx].year;
        cin >> lib[idx].title;
        cin >> lib[idx].price;
    }

    VidyaGamesPrint(lib, 2);
    VidyaGamesHighestPrice(lib, 2,f);

    cout << "\nThe highest price is: " << f << endl;

    cout << "\nFinished.. !" << endl;
    return 0;
}