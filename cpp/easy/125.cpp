#include <iostream>
#include <vector>
#include <string>




bool isPalindrome(std::string);


// Strategy: We will create a vector to hold all valid characters for the palindrome as we can only include alphanumerical values.
// With this vector, we can position a pointer at the front and one at the end, comparing the values of each one until we reach the middle.
// If there is ever a difference in the values for the two pointers, then we know the string is not a palindrome.
int main(){
    std::string s = " ";

    bool result = isPalindrome(s);
    std::cout << result;

    return 0;
}

bool isPalindrome(std::string s) {


    std::vector<char> output;

    // Only append alphanumerical values to the output vector
    for (char character : s) {
        if (isalnum(character)) {
            output.push_back(std::tolower(character));
        }
    }

    // If the output has a size of 0, then automatically a palindrome.
    if (output.size() == 0) {
            return true;
    } 

    // Pointers comparing the two values from beginning to end.
    for (int i = 0; i < (output.size()/2) + 1; i++) {
        if (output[i] != output[output.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}