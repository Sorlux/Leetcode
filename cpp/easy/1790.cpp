#include <iostream>
#include <string>
#include <vector>


// You can only swap 2 indices and get the same string if there are only two indices mismatching and if the characters being swapped are identical

bool areAlmostEqual(std::string s1, std::string s2) {

    int count = 0;

    std::vector<int> positions;

    if (s1.size() != s2.size()) {
        return false;
    }

    for (int i =0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            count++;
            positions.push_back(i);
        }

        if (count > 3) {
            return false;
        }
    }

    if (count == 0) {
        return true;
    }
    else if (count == 2) {
        if (s1[positions[0]] == s2[positions[1]] && s1[positions[1]] == s2[positions[0]]) {
            return true;
        }
        return false; 
    }
    return false;
}

int main() {
    std::string s1 = "bank";
    std::string s2 = "kanb";


    std::cout << areAlmostEqual(s1,s2) << std::endl;

    return 0;
}