class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int longest = 1;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        if (n == 0) {
            return 0;
        }
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int count = 1;
                int x = it;
            
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                count = count + 1;
            }
            longest = max(longest, count);
            }
        }
          return longest;
    }
  
};