class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long result = 1;

        while (b > 0) {
            if (b & 1)
                result = result * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return result;
    }

    long long combination(int n, int r) {
        if (r < 0 || r > n)
            return 0;

        long long numerator = 1;
        long long denominator = 1;

        for (int i = 1; i <= r; i++) {
            numerator = numerator * (n - i + 1) % MOD;
            denominator = denominator * i % MOD;
        }

        return numerator * modPow(denominator, MOD - 2) % MOD;
    }

    int numberOfSets(int n, int k) {
        return combination(n + k - 1, 2 * k);
    }
};