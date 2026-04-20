#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 10;
const int GOPHERS = 10;

int grid[SIZE][SIZE];
bool revealed[SIZE][SIZE];

// Directions (8 neighbors)
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

// Initialize grid
void initialize() {
    // Set everything to 0
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            grid[i][j] = 0;
            revealed[i][j] = false;
        }
    }

    // Place gophers randomly
    int count = 0;
    while(count < GOPHERS){
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        if(grid[x][y] == -1) continue;

        grid[x][y] = -1;
        count++;
    }

    // Calculate neighbor counts
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(grid[i][j] == -1) continue;

            int gopherCount = 0;
            for(int k=0;k<8;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx>=0 && nx<SIZE && ny>=0 && ny<SIZE){
                    if(grid[nx][ny] == -1) gopherCount++;
                }
            }
            grid[i][j] = gopherCount;
        }
    }
}

// Print map
void printMap() {
    cout << "\nMap:\n";
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(revealed[i][j]){
                cout << grid[i][j] << " ";
            } else {
                cout << "+ ";
            }
        }
        cout << endl;
    }
}

// Recursive reveal (for zero cells)
void reveal(int x, int y){
    if(x<0 || x>=SIZE || y<0 || y>=SIZE) return;
    if(revealed[x][y]) return;

    revealed[x][y] = true;

    // If zero, reveal neighbors
    if(grid[x][y] == 0){
        for(int k=0;k<8;k++){
            reveal(x + dx[k], y + dy[k]);
        }
    }
}

int main() {
    srand(time(0));

    initialize();

    int moves = 0;
    int safeCells = SIZE*SIZE - GOPHERS;

    while(true){
        printMap();

        int x,y;
        cout << "Enter coordinates (row col): ";
        cin >> x >> y;

        // Check bounds
        if(x<0 || x>=SIZE || y<0 || y>=SIZE){
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // If already revealed
        if(revealed[x][y]){
            cout << "Already revealed! Try another.\n";
            continue;
        }

        // If gopher → lose
        if(grid[x][y] == -1){
            cout << "You hit a gopher! Game Over!\n";

            // Reveal all
            for(int i=0;i<SIZE;i++)
                for(int j=0;j<SIZE;j++)
                    revealed[i][j] = true;

            printMap();
            break;
        }

        // Reveal cell
        reveal(x,y);
        moves++;

        // Win condition
        if(moves >= safeCells){
            cout << "You win! All safe cells revealed!\n";

            for(int i=0;i<SIZE;i++)
                for(int j=0;j<SIZE;j++)
                    revealed[i][j] = true;

            printMap();
            break;
        }
    }

    return 0;
}