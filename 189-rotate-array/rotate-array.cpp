class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k %= n;

        vector<int> temp(k);

        // Store last k elements
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        // Shift remaining elements right
        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        // Copy temp to front
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};