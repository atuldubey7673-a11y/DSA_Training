class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxOnes = -1;
        int row = 0;

        for (int i = 0; i < mat.size(); i++) {
            int count = 0;

            for (int j = 0; j < mat[i].size(); j++) {
                count += mat[i][j];
            }

            if (count > maxOnes) {
                maxOnes = count;
                row = i;
            }
        }

        return {row, maxOnes};
    }
};