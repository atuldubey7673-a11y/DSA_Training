// class Solution {
// public:
//     int numberOfSubstrings(string s) {

//         int count = 0;
//         int n = s.size();

//         for (int i = 0; i < n; i++) {
//             int hash[3]={0};
//             for (int j = i; j < n; j++) {
//                 hash[s[j] - 'a' ]= 1;
//                 if (hash[0] + hash[1] + hash[2] == 3) {
//                     count = count +(n-j);
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[3] = {-1, -1, -1};
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;

            if (last[0] != -1 && last[1] != -1 && last[2] != -1) {
                ans += min({last[0], last[1], last[2]}) + 1;
            }
        }

        return ans;
    }
};