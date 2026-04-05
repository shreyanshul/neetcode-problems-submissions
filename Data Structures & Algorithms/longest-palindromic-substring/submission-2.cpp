class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = s.substr(0,1);
        int ansLen = 1;
        // Odd length
        for (int i=0; i<n; i++) {
            int l = i;
            int r = i;
            int count = 0;
            while((l>=0 && r<n) && s[l] == s[r]){
                if(r-l+1 > ansLen) {
                    ansLen = r-l+1;
                    ans = s.substr(l, ansLen);
                }
                l--;
                r++;
            }
            
        }

        // Even length
        for (int i=0; i<n; i++) {
            int l = i;
            int r = i+1;
            int count = 0;
            while((l>=0 && r<n) && s[l] == s[r]) {
                if(r-l+1 > ansLen) {
                    ansLen = r-l+1;
                    ans = s.substr(l, ansLen);
                }
                l--;
                r++;
            }
        }

        return ans;
    }
};