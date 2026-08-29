// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int l = 0;
//         int r = 0;
//         int maxlen = 0;
//         int zero = 0;
//         int n = nums.size();
//         while (r < n) {
//             if (nums[r] == 0) {
//                 zero++;
//             }
//             if (zero > k) {
//                 if (nums[l] == 0) {
//                     zero--;
                    
//                 }
//                 l++;
//             }
//             if (zero <= k) {
//                 int len = r - l + 1;
//                 maxlen = max(maxlen, len);
//                 r++;
//             }
//         }
//         return maxlen;
//     }
// };
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int zero = 0;
        int maxlen = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0)
                zero++;

            while (zero > k) {
                if (nums[l] == 0)
                    zero--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};