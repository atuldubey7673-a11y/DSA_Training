class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        // 1,000 -> first comma
        long long p = 1000;

        while (p <= n) {
            ans += n - p + 1;

            // Next comma is needed starting from 1,000,000,
            // then 1,000,000,000, etc.
            p *= 1000;
        }

        return ans;
    }
};