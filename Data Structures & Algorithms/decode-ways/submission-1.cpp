class Solution {
public:
    int numDecodings(string s) {
        // string letters[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
        //                       "K", "L", "M", "N", "O", "P", "Q", "R", "S". "T",
        //                       "U", "V", "W", "X", "Y", "Z"};

        int len = s.size();
        vector<int> count(len, 0);
        count[0] = 1;
        if(s[0]=='0') {
            return 0;
        }
        for(int i=1; i<len; i++) {
            if(s[i]=='0' && !(s[i-1]=='1' || s[i-1]=='2')){
                return 0;
            }
            if(s[i] != '0') {
                count[i] = count[i-1];
            }
            
            //check two digit is possible or not
            int digit1 = s[i-1] - '0';
            int digit2 = s[i] - '0';
            int num = digit1*10 + digit2;

            if(num >=10 && num <=26){
                if(i==1) {
                    count[i] +=1;
                }
                else {
                    count[i] += count[i-2];
                }
            }
            
        }
        return count[len-1];

        // example "1213"
        // 1 -> count[0] = 1;
        // i=1 -> s[1] = '2'
        //     count[1] = count[0] = 1
        //     digit1 = 1
        //     digit2 = 2
        //     num = 1*10+2 = 12
        //     count[1] = 1+1 = 2
        // i=2 -> s[2] = '1'
        //     count[2] = count[1] = 2
        //     digit1 = 2
        //     digit2 = 1
        //     num = 21
        //     count[2] = 2 + 1
        // i=3 -> s[3] = '3'
        //     count[3] = 3
        //     digit1 = 1
        //     digit2 = 3
        //     num = 13
        //     count[3] = 3 + 2
    }
};
