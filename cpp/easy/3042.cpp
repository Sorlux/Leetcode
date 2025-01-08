#include <iostream>
#include <vector>
#include <string>
        

int countPrefixSuffixPairs(std::vector<std::string>&);


int main() {
    std::vector<std::string> words = {"a","aba","ababa","aa"};

    countPrefixSuffixPairs(words);

    return 0;
}
        
// Brute force check every word against every word in front of it in the vector
int countPrefixSuffixPairs(std::vector<std::string>& words) {
        int counter = 0;
        std::string prefix;
        std::string suffix;


        for (int j =0; j < words.size(); j++) {
            for (int i = j+1; i < words.size(); i++) {
                if (words[j].size() > words[i].size()) {
                    continue;
                }

                // splitting the string into a prefix and suffix the size of the substring.
                prefix = words[i].substr(0,words[j].length());
                suffix = words[i].substr(words[i].length() - words[j].length());
                
                if (j != i && prefix == words[j] && suffix == words[j]) {
                    counter++;
                }
            }
        }

        return counter;

}