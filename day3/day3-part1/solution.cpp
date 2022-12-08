#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

char find_character(string& rucksack);
int calculate_points(char item);

int main () {
    ifstream input;
    string line;

    input.open("input.txt");

    if (input.is_open()) {
        int count = 1;
        int sum = 0;

        while (getline(input, line)) {
            int priority = find_character(line);
            cout << "Line " << count << ": priority is " << priority << endl;
            sum += priority;
            count++;
        }
        cout << "\nThe sum of the priorities of each rucksack is: " << sum << endl;
    }   
    else cout << "Unable to open file." << endl; 
}

// Given a rucksack, return the priority of the character that appears in both compartments
char find_character(string& rucksack) {
    int length = rucksack.length();
    int middle = length / 2;
    unordered_map<char, int> appears;

    char c;
    for (int i = 0; i < length; i++) {
        c = rucksack[i];

        
        if (i < middle) appears[c] = 1;
        else {
            if (appears[c] > 0) {
                return calculate_points(c);
            }
        }
    }

    return '?';
}

// Calculate the points of an item type by its priority
int calculate_points(char item) {
    /*
        Lowercase item types a through z have priorities 1 through 26.
        Uppercase item types A through Z have priorities 27 through 52.
    */

    /* 
    Calculate in relation to its ASCII decimal value
    Different calculation between upper and lower case chars
    */
    if (isupper(item))
        return item - 38;
    else
        return item - 96;


}