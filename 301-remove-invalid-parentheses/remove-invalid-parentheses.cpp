class Solution {
public:
    unordered_set<string> ans;

    void solve(string &s, int index, int leftRem, int rightRem,
               int balance, string current) {

        if (index == s.size()) {
            if (leftRem == 0 && rightRem == 0 && balance == 0) {
                ans.insert(current);
            }
            return;
        }

        char ch = s[index];

     
        if (ch == '(' && leftRem > 0) {
            solve(s, index + 1, leftRem - 1, rightRem,
                  balance, current);
        }

        if (ch == ')' && rightRem > 0) {
            solve(s, index + 1, leftRem, rightRem - 1,
                  balance, current);
        }

   
        if (ch != '(' && ch != ')') {
            solve(s, index + 1, leftRem, rightRem,
                  balance, current + ch);
        }
        else if (ch == '(') {
            solve(s, index + 1, leftRem, rightRem,
                  balance + 1, current + ch);
        }
        else if (ch == ')' && balance > 0) {
            solve(s, index + 1, leftRem, rightRem,
                  balance - 1, current + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0;
        int rightRem = 0;

       
        for (char ch : s) {
            if (ch == '(') {
                leftRem++;
            }
            else if (ch == ')') {
                if (leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        string current = "";

        solve(s, 0, leftRem, rightRem, 0, current);

        return vector<string>(ans.begin(), ans.end());
    }
};