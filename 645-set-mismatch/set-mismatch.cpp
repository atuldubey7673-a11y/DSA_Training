class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate = -1, missing = -1;

        for (int x : nums) {
            int idx = abs(x) - 1;
            if (nums[idx] < 0)
                duplicate = abs(x);
            else
                nums[idx] *= -1;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }

        return {duplicate, missing};
    }
};