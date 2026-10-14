// class Solution {
// public:
//     string maxSumOfSquares(int num, int sum) {
        
//     }
// };

// class Solution {
// public:
//     string maxSumOfSquares(int num, int sum) {
      
//         if (sum > num * 9 || sum < num) {
//             return "";
//         }
        
//         string ans = "";
        
//         for (int i = 0; i < num; i++) {
           
//             int take = min(9, sum - (num - i - 1));
//             ans += to_string(take);
//             sum -= take;
//         }
        
//         return ans;
//     }
// };
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
    
        if (sum > num * 9 || sum < 0) {
            return "";
        }
        
        string ans = "";
        
        for (int i = 0; i < num; i++) {
          
            for (int d = 9; d >= 0; d--) {
                if (d <= sum && sum - d <= (num - i - 1) * 9) {
                    ans += to_string(d);
                    sum -= d;
                    break;
                }
            }
        }
        
        return ans;
    }
};