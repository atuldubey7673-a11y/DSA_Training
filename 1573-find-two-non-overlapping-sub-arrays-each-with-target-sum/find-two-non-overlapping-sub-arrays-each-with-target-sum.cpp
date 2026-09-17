class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n = arr.size();
        const int INF = 1e9;
        
        vector<int> best(n, INF);
        
        int left = 0;
        int sum = 0;
        int ans = INF;
        
        for (int right = 0; right < n; right++) {
            
            sum += arr[right];
            
            // Shrink the window
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            
            // If current window has sum = target
            if (sum == target) {
                
                int len = right - left + 1;
                
                // Check if a non-overlapping subarray
                // exists before this window
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, len + best[left - 1]);
                }
                
                // Store shortest valid subarray
                if (right == 0)
                    best[right] = len;
                else
                    best[right] = min(best[right - 1], len);
                
            } 
            else {
                
                // No new valid subarray
                if (right > 0)
                    best[right] = best[right - 1];
            }
        }
        
        return ans == INF ? -1 : ans;
    }
};