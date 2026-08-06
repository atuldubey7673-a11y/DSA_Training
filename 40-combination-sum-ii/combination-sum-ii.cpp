class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int index, vector<int>& candidates, int target) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // No need to continue if current number is too large
            if (candidates[i] > target)
                break;

            temp.push_back(candidates[i]);

            // Move to the next index because each element is used once
            solve(i + 1, candidates, target - candidates[i]);

            temp.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target);

        return ans;
    }
};