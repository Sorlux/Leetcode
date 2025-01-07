#include <iostream>
#include <vector>

int recursive(std::vector<int>&, int, int, int);
int search(std::vector<int>&, int);


int main() {

    std::vector<int> nums = {-1,0,3,5,9,12};
    int k = 9;

    int leftPointer = 0;
    int rightPointer= nums.size()-1;

    std::cout << search(nums, k) << std::endl;
    //std::cout << recursive(nums, k, leftPointer, rightPointer) << std::endl;

    return 0;
}

// Should implement this
int recursive(std::vector<int>& nums, int k, int leftPointer, int rightPointer) {
    return 0;
}


// Strategy: Binary Search involves checking the middle value between two pointers and shifting the pointers based on the midpoint value
// If the mid value is smaller than the target, then shift the left pointer to the midpoint + 1
// If the mid value is larger than the target, then shift the right pointer to the midpoint -1
// Keep looping till the target is found, or the target doesn't exist because the two pointers overlap
int search(std::vector<int>& nums, int target ) {
    int leftPointer = 0;
    int rightPointer = nums.size() - 1;
    int mid;

    while (leftPointer <= rightPointer) {
        // Midpoint between the two pointers
        mid = (leftPointer + rightPointer) / 2;

        if (nums[mid] < target) {
            leftPointer = mid + 1;
        }
        else if (nums[mid] > target) {
            rightPointer = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}



