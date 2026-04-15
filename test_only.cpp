#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ---> Constants for World Size <---
const int HEIGHT = 15; // Changed from 10
const int WIDTH = 30;  // Changed from 20

// ---> Robot Class <---
class robot {
private:
    int direction; // 0: Up, 1: Right, 2: Down, 3: Left
    int energy;
    int ID;
    int moved;
    void turnRight();
    void forward(int &, int &);

public:
    void turnLeft();
    int getID() { return ID; }
    int getDirection() { return direction; } // Getter for drawing
    robot(int);
    void refresh() { moved = 0; }
    void draw();
    void print();
    void move(int &, int &);
};

robot::robot(int id) {
    energy = 50;
    ID = id;
    moved = 0;
    direction = rand() % 4; // Start in a random direction
}

void robot::turnLeft() {
    energy--;
    direction = (direction + 3) % 4;
}

void robot::turnRight() {
    energy--;
    direction = (direction + 1) % 4;
}

void robot::forward(int &x, int &y) {
    energy -= 2;
    if (direction == 0) y--; // Up
    if (direction == 1) x++; // Right
    if (direction == 2) y++; // Down
    if (direction == 3) x--; // Left
}

void robot::draw() {
    // Change representation based on direction
    switch (direction) {
        case 0: cout << "^"; break;
        case 1: cout << ">"; break;
        case 2: cout << "v"; break;
        case 3: cout << "<"; break;
    }
}

void robot::print() {
    cout << "ID " << ID << ": Energy = " << energy << " Direction = " << direction;
}

void robot::move(int &x, int &y) {
    if (moved == 1) return;
    switch (rand() % 4) {
        case 0: turnLeft(); break;
        case 1: turnRight(); break;
        case 2:
        case 3: forward(x, y); break;
    }
    moved = 1;
}

// ---> World Class <---
class world {
private:
    int terrain[WIDTH][HEIGHT];
    robot *bots[WIDTH][HEIGHT];

public:
    void set_up();
    void draw();
    void update();
};

void world::set_up() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            bots[x][y] = NULL;
            terrain[x][y] = rand() % 2;
        }
    }
    // Added 1-2 additional robots (Total of 4 now)
    bots[2][2] = new robot(1);
    bots[7][7] = new robot(2);
    bots[12][4] = new robot(3);  // Additional robot
    bots[25][10] = new robot(4); // Additional robot
}

void world::draw() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (bots[x][y] == NULL) {
                // Custom Terrain Symbols: ~ for 1, # for 0
                if (terrain[x][y] == 1) cout << "~";
                else cout << "#";
            } else {
                bots[x][y]->draw();
            }
        }
        cout << endl;
    }
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (bots[x][y] != NULL) {
                bots[x][y]->print();
                bots[x][y]->refresh();
                cout << "\n";
            }
        }
    }
}

void world::update() {
    int tempx, tempy;
    robot *temp;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (bots[x][y] != NULL) {
                tempx = x;
                tempy = y;
                bots[x][y]->move(tempx, tempy);
                
                // Boundary checking
                if (tempx < 0 || tempx >= WIDTH) tempx = x;
                if (tempy < 0 || tempy >= HEIGHT) tempy = y;
                
                // Collision checking
                if (bots[tempx][tempy] == NULL) {
                    temp = bots[x][y];
                    bots[x][y] = NULL;
                    bots[tempx][tempy] = temp;
                }
            }
        }
    }
}

// --- Main function ---
int main() {
    world a_world;
    srand(time(NULL));
    a_world.set_up();
    
    while (true) {
        a_world.draw();
        a_world.update();
        cout << "Press Enter to update world..." << endl;
        cin.ignore();
    }
    return 0;
}