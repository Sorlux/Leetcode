#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue> // Used for priority_queue

std::vector<int> solution(std::vector<int>, int);

int main() {
    std::vector<int> nums = {4,1,-1,2,-1,2,3};
    int k = 2;

    std::vector<int> result = solution(nums,k);

    return 0;
}


// Strategy: We will use a hashmap to keep track of the counts for each unique number in the vector.
// Then, to correctly select the top k most frequent numbers, we will use a priority_queue which will automatically order the numbers based on the value in the kv pairs.
// The numbers with the highest values will go to the top and from there we just need to select k numbers from the top
std::vector<int> solution(std::vector<int> nums, int k) {

    std::unordered_map<int,int> count;
    for (int number : nums) {
        count[number]++;
    }

    std::vector<int> output;
    std::priority_queue<std::pair<int,int>> queue;

    // Switching the order of the kv pairs in the queue because the queue autmoatically orders based on the first index of the pair
    for (std::pair<int,int> kv : count) {
        queue.push({kv.second,kv.first});
    }

    // Select k elements
    if (k > 0 ) {
        for (int i = 0; i < k; i++) {
            // After saving the value, remove it from the queue to push the next value to the top
            std::pair<int,int> kv = queue.top();
            queue.pop();
            output.push_back(kv.second);
        } 
    }

    return output;

}