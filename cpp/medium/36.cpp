#include <iostream>
#include <vector>
#include <unordered_map>



bool checkRow(std::vector<std::vector<char>>);
bool checkColumn(std::vector<std::vector<char>>);
bool checkCell(std::vector<std::vector<char>>);



int main() {

        std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };


    if(checkRow(board) == false) {
        return false;
    }
    if (checkColumn(board) == false) {
        return false;
    }
    if (checkCell(board) == false) {
        return false;
    }
    
    return true;
}


bool checkRow(std::vector<std::vector<char>> board) {


    for (int i = 0; i < 9; i++) {
        std::unordered_map<char,int> counts;
        for (int j = 0; j < 9; j++) {
            char currNum = board[i][j];

            if (currNum != '.') {
                if (counts[currNum] != 0) {
                    return false;
                }
                counts[currNum]++;    
            }
            
        }
    }

    return true;
}


bool checkColumn(std::vector<std::vector<char>> board) {

    for (int i = 0; i < 9; i++) {
        std::unordered_map<char,int> counts;
        
        for (int j = 0;  j < 9; j++) {
            char currNum = board[j][i];
            if (currNum != '.') {
                if (counts[currNum] != 0 ) {
                    return false;
                }
                counts[currNum]++;
            }
        }
    }

    return true;
}

bool checkCell(std::vector<std::vector<char>> board) {
    
    for (int boxIndex = 0; boxIndex < 9; boxIndex++) {
        std::unordered_map<char,int> counts;

        int startRow = (boxIndex/3) * 3;
        int startCol = (boxIndex % 3) * 3;

        for (int cellIndex = 0; cellIndex < 9; cellIndex++) {
            int row = startRow + (cellIndex / 3);
            int col = startCol + (cellIndex % 3 );

            char currNum = board[row][col]; 
            if (currNum != '.') {
                if (counts[currNum] != 0) {
                    return false;
                }
                counts[currNum];

            }

        }
    }

    return true;

}


