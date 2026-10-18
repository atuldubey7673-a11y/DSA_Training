#include <vector>

class Solution {
private:
    static constexpr long long MOD = 1'000'000'007;
    std::vector<std::vector<long long>> pascal;

    long long countWays(const std::vector<int>& arr) {
        int m = arr.size();
       
        if (m <= 2) {
            return 1;
        }

        int root = arr[0];
        std::vector<int> leftSubtree;;
        std::vector<int> rightSubtree;
        leftSubtree.reserve(m);
        rightSubtree.reserve(m);

        
        for (int i = 1; i < m; ++i) {
            if (arr[i] < root) {
                leftSubtree.push_back(arr[i]);
            } else {
                rightSubtree.push_back(arr[i]);
            }
        }

        long long leftWays = countWays(leftSubtree);
        long long rightWays = countWays(rightSubtree);

       
        long long waysToInterleave = pascal[m - 1][leftSubtree.size()];

       
        long long total = (waysToInterleave * leftWays) % MOD;
        total = (total * rightWays) % MOD;

        return total;
    }

public:
    int numOfWays(std::vector<int>& nums) {
        int n = nums.size();

       
        pascal.assign(n + 1, std::vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            pascal[i][0] = 1;
            pascal[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % MOD;
            }
        }

       
        return (countWays(nums) - 1 + MOD) % MOD;
    }
};