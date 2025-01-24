#include <iostream>
#include <vector>


void reverseString(std::vector<char>& s) {
        int leftPtr = 0;
        int rightPtr = s.size() - 1;

        while (leftPtr < rightPtr) {
            int temp = s[rightPtr];
            s[rightPtr] = s[leftPtr];
            s[leftPtr] = temp;

            leftPtr++;
            rightPtr--;
        }      
}

int main() {

  std::vector<char> s = {'h','e','l','l','o'};
  
  reverseString(s);
  for (char c: s) {
    std::cout << c;
  }

  std::cout << std::endl;
  return 0;
}