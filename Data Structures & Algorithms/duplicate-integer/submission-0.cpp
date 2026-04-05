class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> ust;
        int len = nums.size();
        for(int i=0; i<len; i++) {
            if(ust.find(nums[i])!=ust.end()) {
                return true;
            }
            ust.insert(nums[i]);
        }
        return false;
    }
};