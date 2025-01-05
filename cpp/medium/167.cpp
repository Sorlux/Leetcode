#include <iostream>
#include <vector>


std::vector<int> twoSum(std::vector<int>&, int);


int main() {
    std::vector<int> numbers = {-1,0};
    int target = -1;
    std::vector<int> results;
    results = twoSum(numbers, target);

    for (int number:results) {
        std::cout << number << " ";
    }
    return 0;
}

// We are given that there is exactly one solution to every target and that the vector is ordered.
// Therefore we know that if our current sum is smaller than the target, then we must move the left pointer up to increase the sum.
// If the current sum is larger than the target, then the right pointer must move down to decrease the sum.
std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    
    std::vector<int> output;
    int leftPointer = 0;
    int rightPointer = numbers.size() - 1;
    int sum =  numbers[leftPointer] + numbers[rightPointer];

    while (sum != target) {
        if (sum > target) {
            rightPointer--;
        }
        else if (sum < target) {
            leftPointer++;
        }
        sum = numbers[leftPointer] + numbers[rightPointer];
    }

    // Add one to the indices and return a vector with the two indices that sum up to the target value
    output.push_back(leftPointer+=1);
    output.push_back(rightPointer+=1);

    return output;

    return output; 
}