
class Solution {
    public int minMoves(int[] nums) {
        int mx = 0;
        int sum = 0;

        for (int num : nums) {
            mx = Math.max(mx, num);
            sum += num;
        }

        return (int) mx * nums.length - sum;
    }
}