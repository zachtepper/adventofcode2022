#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int find_character(vector<string>& rucksacks);
int calculate_points(char item);

int main () {
    ifstream input;
    string line;

    input.open("input.txt");

    if (input.is_open()) {
        int count = 1;
        int sum = 0;

        while (!input.eof()) {
            if (input.eof()) break;

            cout << "Group " << count << ": " << endl;

            // Add the three-Elf group rucksacks to an array
            vector<string> rucksacks;
            for (int i = 0; i < 3; i++) {
                getline(input, line);
                rucksacks.push_back(line);

                cout << "\t" << line;
            }
            cout << endl;

            int priority = find_character(rucksacks);

            cout << "Three-Elf group #" << count << ": priority is " << priority << endl << endl;

            sum += priority;
            count++;
        }
        cout << "\nThe sum of the priorities of each group is: " << sum << endl;
    }   
    else cout << "Unable to open file." << endl; 
}

// Given a group of rucksacks, return the priority of the character that appears in all rucksacks
int find_character(vector<string>& rucksacks) {
    int length = rucksacks.size();
    vector<unordered_map<char, int>> maps;

    // Mark all items that are present in each rucksack except for last one
    for (int i = 0; i < length-1; i++) {
        unordered_map<char, int> appears;

        for (char c: rucksacks[i]) {
            appears[c] = 1;
        }

        maps.push_back(appears);
    }

    // Compare against the other maps created
    for (char c : rucksacks[length-1]) {
        unordered_map<char, int> r1 = maps[0];
        unordered_map<char, int> r2 = maps[1];

        if (r1[c] && r2[c]) {
            return calculate_points(c);
        }
    }

    return 0;
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