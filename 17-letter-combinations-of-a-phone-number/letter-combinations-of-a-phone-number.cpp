class Solution {
public:
    vector<string> ans;

    vector<string> keypad = {
        "",     "",     "abc",  "def",
        "ghi",  "jkl",  "mno",  "pqrs",
        "tuv",  "wxyz"
    };

    void solve(string& digits, int index, string current) {

        // All digits have been processed
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        // Get the letters corresponding to current digit
        string letters = keypad[digits[index] - '0'];

        for (char ch : letters) {

            current.push_back(ch);

            solve(digits, index + 1, current);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty()) {
            return {};
        }

        solve(digits, 0, "");

        return ans;
    }
};