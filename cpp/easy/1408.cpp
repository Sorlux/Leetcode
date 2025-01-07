#include <iostream>
#include <vector>
#include <string>


std::vector<std::string> stringMatching(std::vector<std::string>&);

int main(){

    std::vector<std::string> words = {"mass","as","hero","superhero"};
    std::vector<std::string> output = stringMatching(words);
    for (std::string word : output) {
        std::cout << word << " ";
    }
}

// Strategy: Brute force check every word to see if it is a substring of every other word
std::vector<std::string> stringMatching(std::vector<std::string>& words) {

    std::vector<std::string> output;

    // First loop to select subtring
    for (int i = 0; i < words.size(); i++) {
        // Second loop to compare to every word
        for (int j = 0; j < words.size(); j++) {

            //If sub string is found in the comparison, then add the sub string to the output vector
            if ( j != i && words[j].find(words[i]) != std::string::npos) {
                output.push_back(words[i]);
                break;
            }

        }
    }
    
    return output;
}