class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int n = fruits.size();

        unordered_map<int, int> mpp;

        while (r < n) {
            mpp[fruits[r]]++;

            while (mpp.size() > 2) {
                mpp[fruits[l]]--;

                if (mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]);
                }

                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};