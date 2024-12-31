#include <iostream>
#include <vector>
#include <string>




bool isPalindrome(std::string);


// Strategy: We will create a vector to hold all valid characters for the palindrome as we can only include alphanumerical values.
// With this vector, we can position a pointer at the front and one at the end, comparing the values of each one until we reach the middle.
// If there is ever a difference in the values for the two pointers, then we can increment a counter for the number of changes necessary to be a palindrome
// If the counter is above one, then you must delete more than one character to make it a palindrome.
int main(){
    std::string s = "abca";

    bool result = isPalindrome(s);
    std::cout << result;

    return 0;
}

bool isPalindrome(std::string s) {


    std::vector<char> output;
    std::vector<char> original;
    // Only append alphanumerical values to the output vector
    for (char character : s) {
        if (isalnum(character)) {
            output.push_back(std::tolower(character));
            original.push_back(std::tolower(character));
        }
    }

    // If the output has a size of 0, then automatically a palindrome.
    if (output.size() == 0) {
            return true;
    } 

    int counter = 0;
    // Pointers comparing the two values from beginning to end.
    int index;
    int length;

    if (output.size() % 2 == 1) {
        length = output.size()/2 + 1;
    }
    else {
        length = output.size()/2;
    }


    for (int i = 0; i < length; i++) {
        if (output[i] != output[output.size() - 1 - i]) {
            counter++;
            if (counter > 1) {
                return false;
            }
            index = i;
        }
    }

    if (counter == 0) {
        return true;
    }

    output.erase(output.begin() + index);
    length--;

    bool firstCheck;
    bool secondCheck;

    for (int i = 0; i < length; i++) {
        if (output[i] != output[output.size() - 1 - i]) {
            firstCheck = false;
            break;
        }
    }

    original.erase(original.end() - 1 - index);

    for (int i = 0; i < length; i++) {
        if (original[i] != original[original.size() - 1 - i]) {
            secondCheck = false;
            break;
        }
    }

    if (firstCheck == false && secondCheck == false) {
        return false;
    }

    return true;
}