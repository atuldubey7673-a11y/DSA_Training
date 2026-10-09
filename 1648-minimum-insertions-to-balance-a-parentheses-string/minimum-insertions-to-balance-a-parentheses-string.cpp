class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int open = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } 
            else {
                // We need pairs of closing parentheses: ))
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;  // Consume the second ')'
                } 
                else {
                    insertions++; // Insert a missing ')'
                }

                if (open > 0) {
                    open--;
                } 
                else {
                    insertions++; // Insert a missing '('
                }
            }
        }

        // Each remaining '(' needs two ')'
        insertions += open * 2;

        return insertions;
    }
};