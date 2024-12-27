#include <iostream>
#include <vector> // Required for problem
#include <algorithm> // Used for count
#include <unordered_map>





int main() {
    std::vector<int> nums = {1,2,3,1};
    std::unordered_map<int, int> numberCount;

    for (int i = 0; i < nums.size(); i++) {
        // If value is above 0, then we know there is a duplicate of that number
        if (numberCount[nums[i]] > 0) {
            //std::cout << "true";
            return true;
            }
        // Increment number by 1 if it is the first time seeing it.
        numberCount[nums[i]]++;
    }
    //std::cout << "false";
    return false;
    
}