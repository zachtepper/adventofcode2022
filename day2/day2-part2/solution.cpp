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
    {'X', LOSE},
    {'Y', DRAW},
    {'Z', WIN},
};

// Each corresponding value is what you need to play in order to BEAT that key
unordered_map<char, char> what_to_play = {
    {'A', 'B'},
    {'B', 'C'},
    {'C', 'A'},
};

// Each corresponding value is what you need to play in order to LOSE that key
unordered_map<char, char> what_not_to_play = {
    {'B', 'A'},
    {'C', 'B'},
    {'A', 'C'},
};

// This map isn't needed. Using it only for pretty printing & having a verbose program.
unordered_map<char, string> definitions = {
    {'A', "ROCK"},
    {'B', "PAPER"},
    {'C', "SCISSORS"},
    {'X', "LOSE"},
    {'Y', "DRAW"},
    {'Z', "WIN"},
};

/*
    Evaluate what move to play based on the strategy
    Also adds points to the total score
    Returns the correct play according to the given strategy
*/
int evaluate(char& strategy, char& opponent, int& total_score) {
    if (strategy == 'Y') {
        total_score += DRAW + point_values[opponent];
        return opponent;
    }
    else if (strategy == 'Z') {
        total_score += WIN + point_values[what_to_play[opponent]];
        return what_to_play[opponent];
    }
    else {
        total_score += LOSE + point_values[what_not_to_play[opponent]];
        return what_not_to_play[opponent];
    }
    
}

int main() {
    int total_score = 0;

    ifstream input;
    input.open("input.txt");

    char opponent_move;
    char strategy;
    while (!input.eof()) {
        // Get opponent's move then my move
        // Use >> operator to skip any whitespace or newline characters
        input >> opponent_move;
        input >> strategy;

        if (input.eof()) break;

        cout << "Opponent plays: " << definitions[opponent_move] << "\t";
        cout << "The strategy is to: " << definitions[strategy] << endl;

        cout << "I need to play: " << definitions[evaluate(strategy, opponent_move, total_score)] << endl << endl;
    }
    input.close();

    cout << "\n\tTotal points earned: " << total_score << endl;
}