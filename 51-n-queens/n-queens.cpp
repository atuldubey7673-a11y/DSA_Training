class Solution {
public:
    vector<vector<string>> ans;

    void solve(int row, int n, vector<string>& board,
               vector<bool>& col,
               vector<bool>& diag1,
               vector<bool>& diag2) {

        // All queens placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {

            // Check column and diagonals
            if (col[c] || diag1[row + c] || diag2[row - c + n - 1])
                continue;

            // Place queen
            board[row][c] = 'Q';

            col[c] = true;
            diag1[row + c] = true;
            diag2[row - c + n - 1] = true;

            solve(row + 1, n, board, col, diag1, diag2);

            // Backtrack
            board[row][c] = '.';

            col[c] = false;
            diag1[row + c] = false;
            diag2[row - c + n - 1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        vector<bool> col(n, false);

        // There are 2n - 1 diagonals
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        solve(0, n, board, col, diag1, diag2);

        return ans;
    }
};