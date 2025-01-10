#include <iostream>
#include <string>
#include <vector>

int main () {

    std::vector<std::string> words = {"pay","attention","practice","attend"};
    std::string pref = "at";
    std::cout << prefixCount(words, pref);

    return 0;
}


int prefixCount(std::vector<std::string>& words, std::string pref) {
    int count = 0;
    std::string prefix;
    for (std::string word: words) {
        prefix = word.substr(0, pref.size());
        if (prefix == pref) {
            count++;
        }
   
    }
    return count;