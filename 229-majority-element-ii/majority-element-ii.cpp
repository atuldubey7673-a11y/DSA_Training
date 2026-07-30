class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int ,int> mpp;
        vector<int> ls;
        int n = nums.size();

        int min = (int)(n / 3) + 1;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        
        if (mpp[nums[i]] == min) {
            ls.push_back(nums[i]);
        }
        }
        return ls;
    }
};