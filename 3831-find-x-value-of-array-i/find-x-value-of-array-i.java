// class Solution {
//     public long[] resultArray(int[] nums, int k) {

//         long[] ans = new long[k];

//         for (int i = 0; i < nums.length; i++) {

//             long product = 1;

//             for (int j = i; j < nums.length; j++) {

//                 product = (product * nums[j]) % k;

//                 ans[(int) product]++;
//             }
//         }

//         return ans;
//     }
// }
import java.util.*;

class Solution {
    public long[] resultArray(int[] nums, int k) {

        long[] ans = new long[k];

        Map<Integer, Long> map = new HashMap<>();

        for (int num : nums) {

            int x = num % k;

            Map<Integer, Long> next = new HashMap<>();

            // Start a new subarray
            next.put(x, next.getOrDefault(x, 0L) + 1);

            // Extend previous subarrays
            for (Map.Entry<Integer, Long> entry : map.entrySet()) {

                int oldRem = entry.getKey();
                long count = entry.getValue();

                int newRem = (oldRem * x) % k;

                next.put(
                    newRem,
                    next.getOrDefault(newRem, 0L) + count
                );
            }

            // Add to answer
            for (Map.Entry<Integer, Long> entry : next.entrySet()) {
                ans[entry.getKey()] += entry.getValue();
            }

            map = next;
        }

        return ans;
    }
}