class Solution {
public:
    int characterReplacement(string s, int k) {

        int l = 0;
        int r = 0;
        int maxlen = 0;
        int hash[26] = {0};
        int n = s.size();
        int maxfre = 0;

        while (r < n) {
            hash[s[r] - 'A']++;

            maxfre = max(maxfre, hash[s[r] - 'A']);

            if ((r - l + 1) - maxfre > k) {
                hash[s[l] - 'A']--;

                maxfre = 0;

                for (int i = 0; i < 26; i++) {
                    maxfre = max(maxfre, hash[i]);
                }

                l++;
            }

            maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};
// int n=s.size();
// int maxlen=0;
// for(int i=0;i<n;i++){
//     int hash[26]={0};
//     int maxfre=0;
//     for(int j=i;j<n;j++){
//         hash[s[j]-'A']++;
//         maxfre=max(maxfre,hash[s[j]-'A']);
//         int changes=(j-i+1)-maxfre;
//         if(changes<=k){
//             maxlen=max(maxlen,j-i+1);
//         }
//     }
// }
// return maxlen;
