class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // upper left diagonal
        int r = row;
        int c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }
        // left row
         r = row;
         c = col;
        while (c >= 0) {
            if (board[r][c] == 'Q')
                return false;

            c--;
        }
        // lower left diagonal
         r = row;
         c = col;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }
        return true;
    }
    void solve(int col, vector<vector<string>>& ans, vector<string> &board,
               int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row  = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                //backtrack
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
       solve(0,ans,board,n);
       return ans;
        }
    
};