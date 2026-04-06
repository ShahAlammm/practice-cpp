#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;

// ===== Class ====
class square{
private:
    int move;
    int scoreChange;
    string message;
    char symbol;

public:
    square();
    void print();
    int action(int &playerScore);
    void set(int, char, int, string);
};


void print_board(square[], int, int);
void read_board(square[]);
void check_position(int &);

// constants.
const int board_length = 20;

// Main start of the game from here : ========
int main(){
    int current_player = 1, roll;
    int player1_position = 0, player2_position = 0;

    int player1_score = 100;
    int player2_score = 100;

    square the_board[board_length];

    srand(time(NULL));

    // game instructions.
    cout << "=== SURVIVAL GAME ===\n";
    cout << "Reach the safe zone while keeping your health above 0.\n";
    cout << "Special squares can help or hurt you.\n";
    cout << "Player with highest health at the end wins!\n\n";

    read_board(the_board);

    print_board(the_board, player1_position, 1);
    print_board(the_board, player2_position, 2);

    do{
        cout << "\nPlayer " << current_player << " press ENTER to roll...";
        cin.ignore(); 

        roll = 1 + (rand() % 5); // should probably be %6 for dice (1–6)
        cout << "\nPlayer " << current_player << " rolled: " << roll << endl;

        if(current_player == 1){
            player1_position += roll;
            check_position(player1_position);

            player1_position += the_board[player1_position].action(player1_score);
            check_position(player1_position);

            if(player1_score <= 0){
                cout << "Player 1 died! Player 2 Wins!\n";
                return 0;
            }
        }
        else{
            player2_position += roll;
            check_position(player2_position);

            player2_position += the_board[player2_position].action(player2_score);
            check_position(player2_position);

            if(player2_score <= 0){
                cout << "Player 2 died! Player 1 Wins!\n";
                return 0;
            }
        }

        print_board(the_board, player1_position, 1);
        print_board(the_board, player2_position, 2);

        //scores shown after both boards, might be confusing
        cout << "Player 1 Health: " << player1_score << endl;
        cout << "Player 2 Health: " << player2_score << endl;

        current_player = (current_player % 2) + 1;

    }while((player1_position < board_length-1) && (player2_position < board_length-1));

    cout << "\n**=== GAME OVER ===**\n";

// for give 20 bonus. both players can get bonus even if only one finishes first
    if(player1_position == board_length-1)
        player1_score += 20;
    if(player2_position == board_length-1)
        player2_score += 20;

    if(player1_score > player2_score)
        cout << "Player 1 Wins!\n";
    else if(player2_score > player1_score)
        cout << "Player 2 Wins!\n";
    else
        cout << "It's a tie!\n";

    return 0;
}

// Read TXT File
void read_board(square b[]){
    ifstream infile("game.txt");

    int square_number, square_move, square_score;
    string square_message;
    char square_symbol;

    while(infile >> square_number >> square_move >> square_symbol >> square_score){
        getline(infile, square_message);

        if(square_number < board_length)
            b[square_number].set(square_move, square_symbol, square_score, square_message);
    }

}

// Print .
void print_board(square b[], int player_position, int player_number){
    for(int i = 0; i < board_length; i++){
        cout << "|";
        if(i == player_position)
            cout << player_number;
        else
            b[i].print();
    }
    cout << "| Goal\n";

    for(int i = 0; i < board_length; i++)
        cout << "--";
    cout << "\n";

}


// Position check for boundary.
void check_position(int &p){
    if(p < 0) p = 0;
    if(p >= board_length) p = board_length-1;

    // I wanted to show message when player hits boundary but couldn't figure it out.
}

// Square Class
square::square(){
    symbol = ' ';
    move = 0;
    message = "";
    scoreChange = 0;
}

int square::action(int &playerScore){
    cout << message << endl;

    playerScore += scoreChange;

    //  no limit on max health

    return move;
}

void square::print(){
    cout << symbol;
}

void square::set(int m, char s, int sc, string a_message){
    move = m;
    symbol = s;
    scoreChange = sc;
    message = a_message;

}