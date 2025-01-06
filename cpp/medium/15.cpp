#include <iostream>
#include <vector>
#include <algorithm> // Used for sort
#include <set> // Sets will be used to have unique sets of triplets


std::vector<std::vector<int>> threeSum(std::vector<int>&);


int main() {

    std::vector<int> nums = {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> output = threeSum(nums);

}


std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {

    // Will keep track of each triplet and ensure they are unique
    std::set<std::vector<int>> triplets;

    // Will compile together all the values inside the set for the final output
    std::vector<std::vector<int>> output;


    int leftPointer, rightPointer;
    int sum;

    // Sort first so we can move the pointers based on higher/lower sum
    std::sort(nums.begin(), nums.end());

    // General loop that will look at each index and reset the left and right pointers.
    for (int i = 0; i < nums.size(); i++) {
        leftPointer = i + 1;
        rightPointer = nums.size() - 1;

        // Ensure the two pointers don't cross
        while (leftPointer < rightPointer) {
            sum = nums[i] + nums[leftPointer] + nums[rightPointer];
            // Shifts pointers based on the value of the sum and 0, if sum is higher, increase left, if sum is lower, decrease right.
            if (sum < 0) {
                leftPointer++;
            }
            else if (sum > 0) {
                rightPointer--;
            }
            else {
                triplets.insert({nums[i], nums[leftPointer], nums[rightPointer]});
                leftPointer++;
                rightPointer--;
            }
        }

    }

    // Grab all vectors inside the set and put them into a final vector for the output
    for (std::vector<int> numbers: triplets) {
        output.push_back(numbers);
    }

    return output;


    
}