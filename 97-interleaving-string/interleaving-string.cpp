class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length()) {
            return false;
        }

        // Ensure s2 is the shorter string to minimize space to O(min(m, n))
        if (m < n) {
            return isInterleave(s2, s1, s3);
        }

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        // Base case: using 0 characters from s1 and j characters from s2
        for (int j = 1; j <= n; ++j) {
            dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        // Update the 1D DP array row by row
        for (int i = 1; i <= m; ++i) {
            // Using i characters from s1 and 0 characters from s2
            dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);
            
            for (int j = 1; j <= n; ++j) {
                bool from_s1 = dp[j] && (s1[i - 1] == s3[i + j - 1]);
                bool from_s2 = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
                dp[j] = from_s1 || from_s2;
            }
        }

        return dp[n];
    }
};