class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(string &s, int index, vector<string>& current,
               vector<vector<string>>& ans) {
        if (index == s.size()) {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                current.push_back(s.substr(index, i - index + 1));

                solve(s, i + 1, current, ans);

                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current;

        solve(s, 0, current, ans);

        return ans;
    }
};