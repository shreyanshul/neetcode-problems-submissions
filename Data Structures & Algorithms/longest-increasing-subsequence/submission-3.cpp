class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len,1);
        for(int i=1; i<len; i++) {
            for(int j=i-1; j>=0; j--) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }
        int maxi = 0;
        for(auto num : dp) {
            // cout << num << " ";
            maxi = max (maxi, num);
        }
        return maxi;

        // dry run
//         0 3 1 3 2 3
//  output 1 2 2 3 3 4
//      dp 1 1 1 1 1 1
// i=1, dp 1 2 1 1 1 1
// i=2, dp 1 2 2 1 1 1
// i=3, dp 1 2 2 3 1 1
// i=4, dp 1 2 2 3 3 1
// i=5, dp 1 2 2 3 3 4
    }
};
