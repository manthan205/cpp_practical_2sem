
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("data1.txt");

    if (!file) {
        cerr << "Error: Could not open file.\n";
        return 1;
    }

    string input, line;

    while (getline(file, line)) {
        input += line + ' ';
    }

    file.close();

    transform(input.begin(), input.end(), input.begin(), ::tolower);

    stringstream ss(input);
    string word;
    map<string, int> wordCounts;

    while (ss >> word) {
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return !isalnum(c);
        }), word.end());

        if (!word.empty()) {
            wordCounts[word]++;
        }
    }

    cout << "\n--- Word Frequencies ---\n";
    for (const auto& pair : wordCounts) {
        cout << pair.first << ": " << pair.second << endl;
    }
     cout << "24CE103_Manthan Rangpariya" << endl;


    return 0;
}
