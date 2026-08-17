class Solution {
public:
    int countPartitions(vector<int>& nums, long long maxSum) {
        int partitions = 1;
        long long sum = 0;

        for (int x : nums) {
            if (sum + x <= maxSum) {
                sum += x;
            } else {
                partitions++;
                sum = x;
            }
        }

        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = 0;

        for (int x : nums) {
            high += x;
        }

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            int partitions = countPartitions(nums, mid);

            if (partitions > k) {
                
                low = mid + 1;
            } else {
                
                high = mid - 1;
            }
        }

        return low;
    }
};