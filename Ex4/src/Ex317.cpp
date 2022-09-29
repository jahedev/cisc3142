#include <iostream>
#include <vector>

using namespace std;

void string_upper(string &s) {
    for (auto &c : s) {
        c = toupper(c);
    }
}

int main() {
    vector<string> words;

    // read in words and add to vector
    string input_word;
    while (cin >> input_word) {
        words.push_back(input_word);
    }

    // capitalize each word in vector
    for (auto &word : words) {
        string_upper(word);
    }

    // print 8 words at a time
    for (auto word = words.begin(); word != words.end(); ++word) {
        // print 8 words, but stop if we've reached the end
        for (int j = 0; j < 8 && word != words.end(); j++) {
            cout << *word << " ";
            ++word;
        }

        cout << endl; // finish 8 worded lined

        // to avoid segmentation fault
        if (word == words.end()) break;
    }

    return 0;
}