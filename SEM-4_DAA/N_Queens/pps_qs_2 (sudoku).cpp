/*
Question

Consider the Sudoku Problem : You are given a partially filled 9 × 9 grid. The task is to fill the 9 x 9 grid with digits (from 1 to 9) 
so that each column, each row, and each of the nine 3 x 3 subgrids contain all of the digits from 1 to 9. Design a backtracking C++ code to solve the Sudoku problem. 

Algorithm

Define the dimensions of the Sudoku grid as N = 9.
Define a function called printGrid to print the Sudoku grid.
Define a function called findEmptyCell to find the next empty cell in the Sudoku grid.
Define a function called isValid to check if a given value is valid in the Sudoku grid.
Define a function called solveSudoku to solve the Sudoku grid recursively using backtracking.
In the solveSudoku function:
a. Find the next empty cell in the Sudoku grid using the findEmptyCell function.
b. If no empty cell is found, the Sudoku grid is complete - return true to indicate success.
c. For values 1 through 9:
i. If the value is valid in the current cell, fill it in.
ii. Recursively solve the rest of the Sudoku grid using the solveSudoku function.
iii. If the recursive call succeeds, return true to indicate success.
iv. If the recursive call fails, backtrack and try the next value.
d. If no value works, return false to backtrack.
In the main function:
a. Read in the partially filled Sudoku grid from the user.
b. Call the solveSudoku function to solve the Sudoku grid.
c. If the solveSudoku function returns true, print the solved Sudoku grid using the printGrid function.
d. If the solveSudoku function returns false, print a message indicating that no solution was found.
End.

*/

#include <iostream>
using namespace std;

// Define the dimensions of the Sudoku grid
const int N = 9;

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to find the next empty cell in the Sudoku grid
bool findEmptyCell(int grid[N][N], int& row, int& col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Function to check if a given value is valid in the Sudoku grid
bool isValid(int grid[N][N], int row, int col, int value) {
    // Check row and column for same value
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == value || grid[i][col] == value) {
            return false;
        }
    }
    // Check subgrid for same value
    int subgridStartRow = row - row % 3;
    int subgridStartCol = col - col % 3;
    for (int i = subgridStartRow; i < subgridStartRow + 3; i++) {
        for (int j = subgridStartCol; j < subgridStartCol + 3; j++) {
            if (grid[i][j] == value) {
                return false;
            }
        }
    }
    // Value is valid
    return true;
}

// Function to solve the Sudoku grid
bool solveSudoku(int grid[N][N]) {
    int row, col;
    // Find the next empty cell
    if (!findEmptyCell(grid, row, col)) {
        // No empty cell found - solution is complete
        return true;
    }
    // Try values 1 through 9 in the empty cell
    for (int value = 1; value <= 9; value++) {
        if (isValid(grid, row, col, value)) {
            // If value is valid, fill it in
            grid[row][col] = value;
            // Recursively solve the rest of the grid
            if (solveSudoku(grid)) {
                // Solution found
                return true;
            }
            // If recursive call failed, backtrack and try the next value
            grid[row][col] = 0;
        }
    }
    // No valid value found - backtrack
    return false;
}

int main() {
    int grid[N][N];
    cout << "Enter the Sudoku grid (use 0 for empty cells):" << endl;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> grid[row][col];
        }
    }
    if (solveSudoku(grid)) {
        cout << "Solution:" << endl;
        printGrid(grid);
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}
