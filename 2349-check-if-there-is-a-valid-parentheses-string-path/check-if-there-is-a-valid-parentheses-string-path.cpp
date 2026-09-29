class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Valid parentheses string must have even length.
        if ((m + n - 1) % 2 == 1)
            return false;

        // Must start with '(' and end with ')'.
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        vector<vector<unordered_set<int>>> dp(
            m, vector<unordered_set<int>>(n)
        );

        dp[0][0].insert(1);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                int change = (grid[i][j] == '(') ? 1 : -1;

                // From top
                if (i > 0) {
                    for (int bal : dp[i - 1][j]) {
                        int newBal = bal + change;
                        if (newBal >= 0)
                            dp[i][j].insert(newBal);
                    }
                }

                // From left
                if (j > 0) {
                    for (int bal : dp[i][j - 1]) {
                        int newBal = bal + change;
                        if (newBal >= 0)
                            dp[i][j].insert(newBal);
                    }
                }
            }
        }

        return dp[m - 1][n - 1].count(0);
    }
};