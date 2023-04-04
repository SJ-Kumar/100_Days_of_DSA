/*
Question

2. Given a square board B of size n x n, design a back-tracking based c++ code to place all the given n integers: 1,2,3,...n in B such that 
(i) no successive numbers are placed in both the leading diagonals (in leading diagonals: line drawn from the left-most top cell to the right-most bottom cell 
as well as the line drawn from the left-most bottom cell to the right-most top cell ) 
(ii) non-consecutive numbers can be placed in the same row or column of the board B. 

Algorithm

Define a square board B of size n x n and initialize it with zeros.
Define vectors to keep track of available numbers in each row, column, and diagonal.
Define a flag to indicate if a solution has been found.
Define a function can_place(x, y, num) to check if a number can be placed in a cell (x, y) on the board.
Define a function place(x, y, num) to place a number in a cell (x, y) on the board and update the vectors.
Define a function remove(x, y, num) to remove a number from a cell (x, y) on the board and update the vectors.
Define a function backtrack(x, y) to fill the board using backtracking.
If the current cell is already filled, skip to the next cell.
Try placing each available number in the current cell and check if it satisfies the conditions.
If a number can be placed in the current cell, place it and move to the next cell.
If the last cell has been filled, a solution has been found.
If no number can be placed in the current cell, remove the number from the cell and backtrack to the previous cell.
Return the flag indicating if a solution has been found.
In the main function, read the board size from the user and fill a vector nums with integers from 1 to n.
Initialize vectors row, col, diag1, and diag2 with zeros.
Call the backtrack function with the initial cell (0, 0).
If a solution has been found, print the board, otherwise print "No solution".

*/

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10; // maximum board size
const int DIAGONALS = 2; // number of diagonals

int n; // board size
int board[MAXN][MAXN]; // the board
vector<int> row[MAXN], col[MAXN], diag[DIAGONALS]; // vectors to keep track of available numbers in each row, column, and diagonal
bool found_solution; // flag to indicate if a solution has been found

// Function to check if a number can be placed in a cell
bool can_place(int x, int y, int num) {
    return !row[x].empty() && !col[y].empty() && !diag[0].empty() && !diag[1].empty() &&
           row[x][0] <= num && num <= row[x].back() &&
           col[y][0] <= num && num <= col[y].back() &&
           diag[0][0] <= num && num <= diag[0].back() &&
           diag[1][0] <= num && num <= diag[1].back();
}

// Function to place a number in a cell
void place(int x, int y, int num) {
    board[x][y] = num;
    row[x].erase(lower_bound(row[x].begin(), row[x].end(), num));
    col[y].erase(lower_bound(col[y].begin(), col[y].end(), num));
    diag[x == y ? 0 : 1].erase(lower_bound(diag[x == y ? 0 : 1].begin(), diag[x == y ? 0 : 1].end(), num));
}

// Function to remove a number from a cell
void remove(int x, int y, int num) {
    board[x][y] = 0;
    row[x].insert(lower_bound(row[x].begin(), row[x].end(), num), num);
    col[y].insert(lower_bound(col[y].begin(), col[y].end(), num), num);
    diag[x == y ? 0 : 1].insert(lower_bound(diag[x == y ? 0 : 1].begin(), diag[x == y ? 0 : 1].end(), num));
}

// Backtracking function to fill the board
void backtrack(int x, int y) {
    if (x == n && y == 0) { // solution found
        found_solution = true;
        return;
    }
    if (board[x][y] != 0) { // skip cells that are already filled
        if (y == n - 1) { // move to the next row
            backtrack(x + 1, 0);
        } else { // move to the next column
            backtrack(x, y + 1);
        }
        return;
    }
    for (int num : row[x]) { // try placing each available number in the current cell
        if (can_place(x, y, num)) { // check if the number can be placed in the cell
            place(x, y, num);
            if (y == n - 1) { // move to the next row
                backtrack(x + 1, 0);
            } else { // move to the next column
                backtrack(x, y + 1);
            }
            if (found_solution) { // stop backtracking if a solution has been found
                return;
            }
            remove(x, y, num);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize board with zeros

vector<int> nums(n);
for (int i = 0; i < n; i++) {
    nums[i] = i + 1; // Fill nums with integers 1 to n
}

vector<int> row(n, 0); // Initialize row with zeros
vector<int> col(n, 0); // Initialize col with zeros
vector<int> diag1(2 * n - 1, 0); // Initialize diag1 with zeros
vector<int> diag2(2 * n - 1, 0); // Initialize diag2 with zeros

solve(board, nums, row, col, diag1, diag2, 0, 0); // Start backtracking from the top-left corner

return 0;
}
