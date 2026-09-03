class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;

        for (int i = s.size() - 1; i >= 0; i--) {

            // Skip spaces at the end
            if (s[i] == ' ' && count == 0) {
                continue;
            }

            // We reached the beginning of the previous word
            if (s[i] == ' ') {
                break;
            }

            count++;
        }

        return count;
    }
};