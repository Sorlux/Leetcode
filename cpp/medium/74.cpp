#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& , int );

int main() {

    std::vector<std::vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    std::cout << searchMatrix(matrix, target) << std::endl;

    return 0;
}


// Strategy: Because the matrix is defined by m x n, we know that the total number of values in the matrix is m x n
// This lets us use binary search where we can half the area to search through with each iteration.
// To accesss the specific value we can divide by n (# of columns) to get the outside vector index, and the remainder will be the inner vector index.
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    
    int rowSize = matrix.size(); // How many value are in the outer vector
    int columnSize = matrix[0].size(); // How many values in the inner vector
    int leftPointer = 0;
    int rightPointer = columnSize * rowSize -1; // Total number of values - 1 for final index
    int midpoint;
    int currRow;
    int currColumn;

    while (leftPointer <= rightPointer) {
        midpoint = (rightPointer + leftPointer)/2;
        currRow = midpoint/columnSize; // Calculation for the outer vector
        currColumn = midpoint%columnSize; // Calculation for the inner vector

        if (matrix[currRow][currColumn] == target) {
            return true;
        }
        else if (matrix[currRow][currColumn] < target) {
            leftPointer = midpoint + 1;
        }
        else {
            rightPointer = midpoint - 1;
        }
    }

    return false;
}