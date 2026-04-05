class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        vector<int> ans;
        // first window
        for(int i=0; i<k; i++) {
            s.insert(nums[i]);
        }
        ans.push_back(*s.rbegin());
        int len = nums.size();
        for(int i=1; i<len-k+1; i++) {
            // delete first num
            auto it = s.find(nums[i-1]);
            s.erase(it);
            
            // add new num
            s.insert(nums[i+k-1]);

            ans.push_back(*s.rbegin());
        }
        return ans;
    }
};
