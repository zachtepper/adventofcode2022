#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    // Create a ifstream object used only for reading files
    ifstream myfile;
    myfile.open("input.txt");

    // Keep track of each elf's total calories
    int elf_count = 1;
    int elf_total = 0;

    int calories;

    // Keep track of the maximum calories and which elf it is associated to
    int max_total_calories = -1;
    int max_elf = -1;

    // Check if file is open and ready to read
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            if (line.length() > 0) {
                // Convert string to a number
                calories = stoi(line);
                cout << "\t" << calories << " calories";

                elf_total += calories;
            }
            else {
                // Done reading a single elf's data
                cout << "Elf #" << elf_count << " total elf calories: " << elf_total << endl;

                // Check if this elf beats current maximum
                if (elf_total > max_total_calories) {
                    max_total_calories = elf_total;
                    max_elf = elf_count;
                }

                // Reset count for next elf
                elf_count++;
                elf_total = 0;
            }
            cout << endl;
        }
        // Done reading a single elf's data, display their total calories
        cout << "Elf #" << elf_count << " total elf calories: " << elf_total << endl << endl;

        // Close file after reading
        myfile.close();

        // Display elf with the most calories
        cout << "Elf #" << max_elf << " is carrying the most calories at " << max_total_calories << "!" << endl;
    } 
    else cout << "unable to open file." << endl;

}