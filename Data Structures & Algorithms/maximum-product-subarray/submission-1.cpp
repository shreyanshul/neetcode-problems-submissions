class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int ans = nums[0];

        int prod = 1;
        for(int i=0; i<len; i++) {
            prod = prod * nums[i];
            ans = max(ans, prod);
            if(nums[i]==0) {
                prod = 1;
            }
        }

        prod = 1;
        for(int i = len-1; i>=0; i--){
            prod = prod * nums[i];
            ans = max(ans, prod);
            if(nums[i]==0) {
                prod = 1;
            }
        }
        
        return ans;
    }
};
