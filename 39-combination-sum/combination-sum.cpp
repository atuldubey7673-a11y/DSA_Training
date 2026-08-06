class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int index, vector<int>& candidates, int target) {

        // Target achieved
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // Out of bounds
        if (index == candidates.size()) {
            return;
        }

        // Take current element
        if (candidates[index] <= target) {
            temp.push_back(candidates[index]);
            solve(index, candidates, target - candidates[index]);
            temp.pop_back();   // Backtrack
        }

        // Skip current element
        solve(index + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target);
        return ans;
    }
};