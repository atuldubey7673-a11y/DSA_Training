class Solution {
public:

    bool possible(vector<int>& bloomDay, int days, int m, int k) {

        int count = 0;
        int noOfbouquets = 0;

        int n = bloomDay.size();

        for (int i = 0; i < n; i++) {

            if (bloomDay[i] <= days) {
                count++;
            }
            else {
                noOfbouquets += count / k;
                count = 0;
            }
        }

        // Process the last group
        noOfbouquets += count / k;

        return noOfbouquets >= m;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {

        if (1LL * m * k > bloomDay.size()) {
            return -1;
        }

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};