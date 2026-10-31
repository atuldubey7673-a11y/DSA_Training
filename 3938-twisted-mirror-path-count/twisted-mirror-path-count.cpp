
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();


        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(2, 0))
        );

        dp[0][0][0] = 1;
        dp[0][0][1] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                int left = 0, up = 0;

                if (j > 0)
                    left = dp[i][j - 1][0];

                if (i > 0)
                    up = dp[i - 1][j][1];

                if (grid[i][j] == 1) {
                    dp[i][j][0] = up;
                    dp[i][j][1] = left;
                }
                else {
                    int total = (left + up) % MOD;

                    dp[i][j][0] = total;
                    dp[i][j][1] = total;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};
