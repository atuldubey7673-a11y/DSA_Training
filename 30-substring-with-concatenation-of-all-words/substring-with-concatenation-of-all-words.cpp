class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int n = words.size();
        int wordLen = words[0].size();
        int totalLen = n * wordLen;

        unordered_map<string, int> mp;

        // Count required words
        for (string word : words) {
            mp[word]++;
        }

        // Try each possible starting offset
        for (int start = 0; start < wordLen; start++) {

            int left = start;
            int right = start;
            int count = 0;

            unordered_map<string, int> seen;

            while (right + wordLen <= s.size()) {

                string word = s.substr(right, wordLen);
                right += wordLen;

                // Word is not present in words
                if (mp.find(word) == mp.end()) {
                    seen.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                seen[word]++;
                count++;

                // Too many occurrences of this word
                while (seen[word] > mp[word]) {
                    string removeWord = s.substr(left, wordLen);

                    seen[removeWord]--;
                    count--;
                    left += wordLen;
                }

                // We have exactly all words
                if (count == n) {
                    ans.push_back(left);
                }
            }
        }

        return ans;
    }
};