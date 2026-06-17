class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string s : strs) {
            ans += (to_string(s.size()) + "#" + s);
        }
        return ans;
    }

    // 3#abc12#abcdefgthijkl2#dk
    vector<string> decode(string s) {
        int len = s.size();
        vector<string> strs;
        for(int i=0; i<len; ){
            string slen = "";
            while(i<len && s[i]!='#'){
                slen.push_back(s[i]);
                i++;
            };
            int slength = stoi(slen);
            string newString = s.substr(i+1, slength);
            strs.push_back(newString);
            i += (slength+1);
        }
        return strs;
    }
};
