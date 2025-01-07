#include <iostream>
#include <vector>
#include<algorithm> // sort


int minEatingSpeed(std::vector<int>&, int);

int main() {

    std::vector<int> piles = {30,11,23,4,20};
    int h = 6;

    std::cout << minEatingSpeed(piles, h);
    return 0;
}

// Strategy: We can use binary search using the values instead of the indices of the vector to find the min number of time required to finish in h hours.
// We can keep track of the number of hours required by a given k by dividing the value of each index by k and adding 1 due to the dividion operator finding the floor.
int minEatingSpeed(std::vector<int>& piles, int h) {
    int counter; // Keeps track of number of hours needed for current k
    std::sort(piles.begin(), piles.end());

    int leftPointer = 1;
    int rightPointer = piles[piles.size() - 1];
    int midPoint;
    
    // If the size of the vector and h are the same then k must be the max value
    if (h == piles.size()) {
        return rightPointer;
    } 

    while (leftPointer < rightPointer) {
        midPoint = (leftPointer + rightPointer)/2;
        counter = 0;
        for (int pile: piles) {
            counter += ((pile-1)/midPoint) + 1; // pile -1 to include situations like pile value = 20, midpoint = 10. +1 because the output of the dividion sign is a floor, and we want the ceiling.
        }

        if (counter > h) {
            leftPointer = midPoint + 1;
        }
        else {
            rightPointer = midPoint; // Keep midPoint because rightPointer moves only when k is valid, or greater than h. This means it is still a valid candidate, but we must check if a smaller value exists. 
        }
    }
    return leftPointer;
}