#include <iostream>
#include <vector>


std::vector<int> twoSum(std::vector<int>&, int);


int main() {
    std::vector<int> numbers = {2,7,11,15};
    int target = 9;
    std::vector<int> results;
    results = twoSum(numbers, target);
    return 0;
}


std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    
    std::vector<int> output;
    int leftPointer = 0;
    int rightPointer = numbers.size() - 1;
    int sum = NULL;

    while (sum != target) {
        sum = numbers[leftPointer] + numbers[rightPointer];

        if (sum > target) {
            
        }
    }

    return output; 
}