/*
Name: Shah Alam
Assignment: 11
Section: 12
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int SIZE = 10;
const int TOTAL_GOPHERS = 10;

// Initialize all boards
void setup(bool gopher[SIZE][SIZE], int count[SIZE][SIZE], bool reveal[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            gopher[i][j] = false;
            count[i][j] = 0;
            reveal[i][j] = false;
        }
    }
}

// Check if inside board
bool valid(int r, int c) {
    return (r >= 0 && r < SIZE && c >= 0 && c < SIZE);
}

// Place gophers randomly
void addGophers(bool gopher[SIZE][SIZE]) {
    int placed = 0;

    while (placed < TOTAL_GOPHERS) {
        int r = rand() % SIZE;
        int c = rand() % SIZE;

        if (!gopher[r][c]) {
            gopher[r][c] = true;
            placed++;
        }
    }
}

// Count nearby gophers
void countNeighbors(bool gopher[SIZE][SIZE], int count[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {

            if (gopher[r][c]) {
                count[r][c] = -1;
                continue;
            }

            int total = 0;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {

                    if (i == 0 && j == 0) continue;

                    int nr = r + i;
                    int nc = c + j;

                    if (valid(nr, nc) && gopher[nr][nc]) {
                        total++;
                    }
                }
            }

            count[r][c] = total;
        }
    }
}

// Print board
void showBoard(int count[SIZE][SIZE], bool reveal[SIZE][SIZE],
               bool gopher[SIZE][SIZE], bool showAll) {

    cout << "\n   ";
    for (int i = 0; i < SIZE; i++) cout << i << " ";
    cout << "\n";

    for (int r = 0; r < SIZE; r++) {
        cout << r << "  ";

        for (int c = 0; c < SIZE; c++) {
            if (reveal[r][c]) {
                cout << count[r][c] << " ";
            }
            else if (showAll && gopher[r][c]) {
                cout << "G ";
            }
            else {
                cout << "+ ";
            }
        }
        cout << "\n";
    }
}

// Reveal safe cells (simple version)
void revealCells(int r, int c, int count[SIZE][SIZE],
                 bool gopher[SIZE][SIZE], bool reveal[SIZE][SIZE],
                 int &safeCount) {

    if (!valid(r, c) || reveal[r][c] || gopher[r][c]) return;

    reveal[r][c] = true;
    safeCount++;

    // If zero, reveal neighbors
    if (count[r][c] == 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                revealCells(r + i, c + j, count, gopher, reveal, safeCount);
            }
        }
    }
}

int main() {
    bool gopher[SIZE][SIZE];
    int count[SIZE][SIZE];
    bool reveal[SIZE][SIZE];

    int safeCells = 0;
    int totalSafe = SIZE * SIZE - TOTAL_GOPHERS;

    srand(time(0));

    setup(gopher, count, reveal);
    addGophers(gopher);
    countNeighbors(gopher, count);

    cout << "=== Gopher Hunt Game ===\n";

    while (true) {
        showBoard(count, reveal, gopher, false);

        int r, c;
        cout << "Enter row: ";
        cin >> r;
        cout << "Enter column: ";
        cin >> c;

        if (!valid(r, c)) {
            cout << "Invalid position!\n";
            continue;
        }

        if (reveal[r][c]) {
            cout << "Already opened!\n";
            continue;
        }

        if (gopher[r][c]) {
            cout << "You hit a gopher! Game Over!\n";
            showBoard(count, reveal, gopher, true);
            break;
        }

        revealCells(r, c, count, gopher, reveal, safeCells);

        if (safeCells == totalSafe) {
            cout << "You Win!\n";
            showBoard(count, reveal, gopher, true);
            break;
        }
    }

    return 0;
}