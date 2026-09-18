class Solution {
public:

    int getRight(string &s, int start,
                 vector<int> &first,
                 vector<int> &last) {

        int end = last[s[start] - 'a'];

        for (int i = start; i <= end; i++) {

            // This character appeared before start,
            // so we cannot create a valid substring
            // starting at 'start'.
            if (first[s[i] - 'a'] < start)
                return -1;

            // We must include every occurrence
            // of this character.
            end = max(end, last[s[i] - 'a']);
        }

        return end;
    }

    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find first and last occurrence
        for (int i = 0; i < n; i++) {

            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Try every possible starting character
        for (int i = 0; i < n; i++) {

            // Only start from the first occurrence
            // of a character.
            if (i != first[s[i] - 'a'])
                continue;

            int end = getRight(s, i, first, last);

            if (end != -1) {
                intervals.push_back({end, i});
            }
        }

        // Sort by ending position
        sort(intervals.begin(), intervals.end());

        vector<string> ans;

        int previousEnd = -1;

        for (auto [end, start] : intervals) {

            // Non-overlapping
            if (start > previousEnd) {

                ans.push_back(
                    s.substr(start, end - start + 1)
                );

                previousEnd = end;
            }
        }

        return ans;
    }
};