class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> mpp;
        vector<int> ls;
        int n = nums.size();

        int limit = n / 3;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;

            if (mpp[nums[i]] == limit + 1) {
                ls.push_back(nums[i]);
            }
        }

        return ls;
    }
};