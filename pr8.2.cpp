
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

void countWordFrequency(const string& input) {
    map<string, int> wordCount;  // Associative container to store words and their frequencies
    string word;
    stringstream ss(input);  // Using stringstream to extract words from the input string

    // Extract words from the input sentence
    while (ss >> word) {
        // Normalize the word to lowercase (if case-insensitivity is required)
        for (char& c : word) {
            c = tolower(c);
        }
        // Increment the count for the current word
        wordCount[word]++;
    }

    // Display the results
    cout << "\nWord Frequency Distribution:\n";
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    string input;

    // Get input sentence from the user
    cout << "Enter a sentence: ";
    getline(cin, input);

    // Call function to count word frequency
    countWordFrequency(input);

    cout<<endl;
    cout<<"24CE103_Manthan Rangpariya"<<endl;
    return 0;
}

