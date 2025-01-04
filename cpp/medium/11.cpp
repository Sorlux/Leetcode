#include <iostream>
#include <vector>


int maxArea(std::vector<int>&);

int main() {

    std::vector<int> height = {1,8,6,2,5,4,8,3,7};

    std::cout << maxArea(height);

    return 0;
}


// We know that area for the water will be equal to min(h1,h2) * width.
// Where width is the distance between the two sides of the container and h is the height of the two sides.
// Therefore, we know that this problem is dependent on those two factors so we need to control how we change the two values.
// If we start at the maximum distance and want to compare a new container, we know that the only thing that would possibly increase the container area is increasing the minimmum height of one side
// Changing the max height to be smaller does not help, therefore we must change the pointer which is currently pointing the min height to try to increase it.
int maxArea(std::vector<int>& height) {
    int max = 0;

    int leftPointer = 0;
    int rightPointer = height.size() - 1;
    int currArea = 0;
    while (leftPointer < rightPointer) {
        // If the left pointer has a lower height than the right, then the area is determined by it and the pointer should move closer to possibly increase area.
        if (height[leftPointer] < height[rightPointer]) {
            currArea = height[leftPointer] * (rightPointer - leftPointer);
            leftPointer++;
        }
        else {
        // If the right pointer has a lower height than the left, then the area is determined by it and the pointer should move closer to possibly increase area. 
            currArea = height[rightPointer] * (rightPointer - leftPointer);
            rightPointer--;
        }
        
        if (currArea > max) {
            max = currArea; 
        }
         
    }

    return max;
}