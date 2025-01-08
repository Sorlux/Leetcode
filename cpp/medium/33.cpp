#include <iostream>
#include <vector>

int search(std::vector<int>&, int);

int main() {

    std::vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    std::cout << search(nums, target);

    return 0;
}


int search(std::vector<int>& nums, int target) {
    int leftPointer = 0;
    int rightPointer = nums.size()-1;
    int midpoint;

    while (leftPointer <= rightPointer) {
        midpoint = leftPointer + (rightPointer - leftPointer)/2;

        if (nums[midpoint] == target) {
            return midpoint;
        }

        if (nums[leftPointer] <= nums[midpoint]) {
            if (nums[leftPointer] <= target && target < nums[midpoint]) {
                rightPointer = midpoint - 1;
            }
            else {
                leftPointer = midpoint + 1;
            }
        }
        else  {
            if (nums[midpoint] < target && target <= nums[rightPointer]) {
                leftPointer = midpoint + 1;
            }
            else {
                rightPointer = midpoint - 1;
            }
        }   
    }   
    return -1;
}



