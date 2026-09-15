class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // isPal[i][j] = whether s[i...j] is palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 2 || isPal[i + 1][j - 1])) {
                    
                    isPal[i][j] = true;
                }
            }
        }

        // dp[i] = maximum number of non-overlapping
        // palindromes from index i onwards
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            // Don't take anything starting at i
            dp[i] = dp[i + 1];

            // Try every palindrome starting at i
            for (int j = i + k - 1; j < n; j++) {

                if (isPal[i][j]) {
                    dp[i] = max(dp[i],
                                1 + dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};