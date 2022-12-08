#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

// Corresponding points for each move
const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;

// Coreresponding points for each game outcome
const int LOSE = 0;
const int DRAW = 3;
const int WIN = 6;

// Map a symbol to their value
unordered_map<char, int> point_values = {
    {'A', ROCK},
    {'B', PAPER},
    {'C', SCISSORS},
    {'X', ROCK},
    {'Y', PAPER},
    {'Z', SCISSORS},
};

// Each key maps to which opponent move they beat (e.g. X beats C)
unordered_map<char, char> logic = {
    {'X', 'C'},
    {'Y', 'A'},
    {'Z', 'B'},
};

// This map isn't needed. Using it only for pretty printing & having a verbose program.
unordered_map<char, string> definitions = {
    {'A', "ROCK"},
    {'B', "PAPER"},
    {'C', "SCISSORS"},
    {'X', "ROCK"},
    {'Y', "PAPER"},
    {'Z', "SCISSORS"},
};

/*
    Evaluate if my move beats the opponent, loses, or draws
    Also adds points to the total score
    Returns the outcome of the match
*/
int evaluate(char& me, char& opponent, int& total_score) {
    int move_score = point_values[me];

    if (point_values[me] == point_values[opponent]) {
        total_score += DRAW + move_score;
        return DRAW;
    }
    else if (logic[me] == opponent) {
        total_score += WIN + move_score;
        return WIN;
    }
    else {
        total_score += LOSE + move_score;
        return LOSE;
    }
}

int main() {
    int total_score = 0;

    ifstream input;
    input.open("input.txt");

    char opponent_move;
    char my_move;
    while (!input.eof()) {
        // Get opponent's move then my move
        // Use >> operator to skip any whitespace or newline characters
        input >> opponent_move;
        input >> my_move;

        if (input.eof()) break;

        cout << "Opponent plays: " << definitions[opponent_move] << "\t";
        cout << "I play: " << definitions[my_move] << endl;

        switch (evaluate(my_move, opponent_move, total_score))
        {
        case DRAW:
            cout << DRAW << " It's a draw!\n" << endl;
            break;
        
        case WIN:
            cout << WIN << " I won!\n" << endl;
            break;
        
        case LOSE:
            cout << LOSE << " ... i lost..\n" << endl;
            break;
        
        default:
            break;
        }
    }
    input.close();

    cout << "\n\tTotal points earned: " << total_score << endl;
}