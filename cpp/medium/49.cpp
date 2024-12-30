#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm> // For sort

// Strategy: If you sort a word, then it must be identical to any other word that is an anagram.
// Therefore, create a hashmap which has the sorted version of every unique anagram and have the value be a vector containg each original word that sorts to that anagram.
// Afterwards you can iterate through each of the keys and push_back the vlaues to another vector which will be returned as the output  



int main() {

    solution();
    return 0;

}


std::vector<std::vector<std::string>> solution() {

    
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    
    std::unordered_map<std::string,std::vector<std::string>> anagrams;
    std::vector<std::string> keys;

    for (int i = 0; i < strs.size(); i++) {
        std::string word = strs[i];

        // Sort the word before adding it to the hashmap as the key
        std::sort(word.begin(), word.end());

        // If it is a new anagram, then make sure to add the word to the keys vector to later access each key
        // Note that depending on the c++ version, you can use auto to iterate through the key value pairs and just push_back the value using  .second()
        if (anagrams.find(word) == anagrams.end()) {
            keys.push_back(word);
        } 
        anagrams[word].push_back(strs[i]);
    }


    std::vector<std::vector<std::string>> groups;

    for (std::string key : keys) {
        groups.push_back(anagrams[key]);
    }

    return groups;
}