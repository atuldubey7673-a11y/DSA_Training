class Solution {
public:
    long long solve(int i, int j, string &s, string &t,
                    vector<vector<long long>> &dp) {

        // t is completely matched
        if (j == t.size())
            return 1;

        // s is exhausted but t is not
        if (i == s.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long ans = 0;

        // Skip s[i]
        ans = solve(i + 1, j, s, t, dp);

        // Take s[i] if it matches
        if (s[i] == t[j]) {
            ans += solve(i + 1, j + 1, s, t, dp);
        }

        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<long long>> dp(m, vector<long long>(n, -1));

        return solve(0, 0, s, t, dp);
    }
};