#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


int main() {

    
    std::string s = "rat";
    std::string t = "car";

    // quick comparison to ensure both strings have the same number of characters
    if (s.size() != t.size()) {
        return false;
    }
    
    std::unordered_map<char, int> sMap;
    std::unordered_map<char, int> tMap;
    std::vector<char> letters;

    // Determines the quantity of each letter in the string s and adds the unique letters to a vector
    for (int i = 0; i < s.size(); i++) {
        if (sMap[s[i]] == 0) {
            letters.push_back(s[i]);
        }

        sMap[s[i]]++;

    }

    // Determines quantity of each letter in string t
    for (int i = 0; i < t.size(); i++) {
        tMap[t[i]]++;
    }

    // Checks that each of the keys has the same quantity for each letter
    // If the quantity per letter matches up, then that means you can create the string s from the letters in string t
    for (int i = 0; i < letters.size(); i++) {
        if (sMap[letters[i]] != tMap[letters[i]]) {
            std::cout << "false";
            return false;
        }
    }

    std::cout << "true";
    return true;
}