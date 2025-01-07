#include <iostream>
#include <vector>

int findMin(std::vector<int>&);


int main() {

    std::vector<int> nums = {3,1,2};

    std::cout << findMin(nums);

    return 0;
}

// Strategy: Just binary serach but we are comparing the values of the midpoint against one pointer to keep halving our search area
int findMin(std::vector<int>& nums) {

    int leftPointer = 0;
    int rightPointer = nums.size()-1;
    int midpoint;

    while (leftPointer < rightPointer) {
        midpoint = leftPointer + (rightPointer - leftPointer)/2;

        if (nums[rightPointer] < nums[midpoint]) {
            leftPointer = midpoint + 1; // We know that the midpoint can't possibly be the min value
        }
        else if (nums[rightPointer] > nums[midpoint]){
            rightPointer = midpoint; // The midpoint is less than the right pointer which means it is still a candidate
        }
    
    }
    return nums[leftPointer]; 
}
