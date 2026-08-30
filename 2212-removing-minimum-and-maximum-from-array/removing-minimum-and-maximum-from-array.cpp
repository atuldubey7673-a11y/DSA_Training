class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        int ans1 = max(minIndex, maxIndex) + 1;
        int ans2 = n - min(minIndex, maxIndex);
        int ans3 = min(minIndex, maxIndex) + 1
                 + n - max(minIndex, maxIndex);

        return min({ans1, ans2, ans3});
    }
};