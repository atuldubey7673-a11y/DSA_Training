class Solution {
public:

    void solve(vector<int>& nums, vector<int>& temp,
               vector<int>& visited, vector<vector<int>>& ans) {

        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (visited[i])
                continue;

            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;

            visited[i] = 1;
            temp.push_back(nums[i]);

            solve(nums, temp, visited, ans);

            temp.pop_back();
            visited[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> visited(nums.size(), 0);

        solve(nums, temp, visited, ans);

        return ans;
    }
};