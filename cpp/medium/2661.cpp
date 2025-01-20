#include <iostream>
#include <unordered_map>
#include<vector>

// 0 indexed integer array and an m x n matrix which both contain all the numbers bettern 1 and mxn
// go through each index in the array starting at 0, and paint the celll in the matrix containing the current value at index i
// Return the smalllest index i at which either a row or column will be completely painted in the matrix

// Basicallly loop through the vector until all values in either a column or row for the matrix have been seen and return the current index of the array
// Need to figure out a way to keep track of numbers that have already been seen
// Maybe there is a way to group together all the columns and rows together and keept track of a count until the count hits the required amount





int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat) {

    int rows = mat.size();
    int columns = mat[0].size();

    // Map matrix values to their flattened indices
    std::vector<int> allNumbers(rows * columns + 1, 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int currentValue = mat[i][j];
            allNumbers[currentValue] = i * columns + j;
        }
    }

    // Initialize counters for painted rows and columns
    std::vector<int> paintedRowsCount(rows, 0);
    std::vector<int> paintedColumnsCounts(columns, 0);

    // Iterate through the array
    for (int i = 0; i < arr.size(); i++) {
        int currNumber = arr[i];
        int coords = allNumbers[currNumber];

        // Calculate the row and column of the current number
        int row = coords / columns;
        int col = coords % columns;

        paintedRowsCount[row]++;
        paintedColumnsCounts[col]++;

        // Check if the current row or column is completely painted
        if (paintedRowsCount[row] == columns || paintedColumnsCounts[col] == rows) {
            return i;
        }
    }

    return -1; // Return -1 if no row or column is fully painted
}
 
int main() {
    
    std::vector<int> arr = {8,2,4,9,3,5,7,10,1,6};
    std::vector<std::vector<int>> mat = {{8,2,9,10,4},{1,7,6,3,5}};

    std::cout << firstCompleteIndex(arr, mat) << std::endl;

    return 0;
}