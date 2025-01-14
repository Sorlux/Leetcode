#include <iostream>
#include <string>
#include <vector>

// Strategy: THe theory behind this is that whenever we move up an index, at most we are introducing 2 new numbers which means we can only add two the previous index keeping count
// We can keep track of the count of each number by using a vector and just accessing the index that corresponds to the value in A or B
std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
    int size = B.size();

    std::vector<int> output(size+1, 0); // Fills a vector of size + 1 full of zeros to keep count
    std::vector<int> result(size); // Actual sequence of results

    output[A[0]]++;
    output[B[0]]++;
    if (output[A[0]] == 2) { // Base case so that we aren't accessing indices outside our vector range
        result[0] += 1; 
    }


    for (int i = 1; i < size; i++) {
        output[A[i]]++;
        output[B[i]]++;
        
        if (A[i] == B[i]) { // If the two indices are the same number then just add one to our count
            result[i] = result[i-1] + 1; 
        }
        else if (output[A[i]] == 2 & output[B[i]] == 2) { // If the two indices are different numbers but both result in 2, then we add 2 to count because thos numbers exist before the current index
            result[i] = result[i-1] + 2;
        }
        else if (output[A[i]] == 2) { // If only A results in 2, then add 1
            result[i] = result[i-1] + 1;
        }
        else if (output[B[i]] == 2) { // If only B results in 2, then add 1 (this should be combined into an or statement really)
            result[i] = result[i-1] + 1;
        }
        else {
            result[i] = result[i-1]; // If none of the other conditions are true then nothing has changed
        }
    }
    return result;
}

 int main() { 
    return 0;
 }

 