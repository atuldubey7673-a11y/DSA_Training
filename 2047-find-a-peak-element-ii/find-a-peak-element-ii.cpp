class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int current = mat[i][j];

                // Check up
                if (i > 0 && mat[i - 1][j] > current)
                    continue;

                // Check down
                if (i < m - 1 && mat[i + 1][j] > current)
                    continue;

                // Check left
                if (j > 0 && mat[i][j - 1] > current)
                    continue;

                // Check right
                if (j < n - 1 && mat[i][j + 1] > current)
                    continue;

                return {i, j};
            }
        }

        return {-1, -1};
    }
};