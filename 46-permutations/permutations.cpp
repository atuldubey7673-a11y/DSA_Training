class Solution {
public:
    void permutations(int index, vector<int>& nums, vector<vector<int>>& ans,
                      int n) {
        if (index == n) {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < n; i++) {
            swap(nums[index], nums[i]);
            permutations(index + 1, nums, ans, n);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        permutations(0, nums, ans, n);
        return ans;
    }
};