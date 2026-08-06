class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int index, vector<int>& nums) {

        // One subset is ready
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Include current element
        temp.push_back(nums[index]);
        solve(index + 1, nums);

        // Backtrack
        temp.pop_back();

        // Exclude current element
        solve(index + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        solve(0, nums);

        return ans;
    }
};