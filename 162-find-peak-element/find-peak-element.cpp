class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            // Prevent potential integer overflow compared to (left + right) / 2
            int mid = left + (right - left) / 2;
            
            // If descending slope, peak is to the left (including mid)
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } 
            // If ascending slope, peak is to the right (excluding mid)
            else {
                left = mid + 1;
            }
        }
        
        // left and right will converge on the peak index
        return left;
    }
};