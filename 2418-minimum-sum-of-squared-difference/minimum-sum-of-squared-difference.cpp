
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<int> diff(n);
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        long long total = 0;
        for (int x : diff) {
            total += x;
        }

        if (total <= k) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int x : diff) {
                if (x > mid) {
                    need += x - mid;
                }
            }

            if (need <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int level = low;
        long long ans = 0;

        for (int x : diff) {
            int reduced = min(x, level);
            ans += 1LL * reduced * reduced;
            k -= x - reduced;
        }

        
        for (int x : diff) {
            if (k == 0) break;

            if (x >= level && level > 0) {
                ans -= 1LL * level * level;
                ans += 1LL * (level - 1) * (level - 1);
                k--;
            }
        }

        return ans;
    }
};
