class Solution {
public:
    int findChange(vector<int>& coins, int amount, vector<int>& dp) {
        if(dp[amount]!=-1) {
            return dp[amount];
        }
        int len = coins.size();

        int ans = INT_MAX;
        for(int i=0; i<len; i++) {
            if(amount >= coins[i]) {
                int changes = findChange(coins, amount - coins[i], dp);
                if(changes != INT_MAX) {
                    ans = min(ans, 1+changes);
                }
            }
        }
        dp[amount] = ans;
        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();

        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        // for(int i=0; i<len;i++) {
        //     if(coins[i] <= amount) {
        //         dp[coins[i]] = 1;
        //     }
        // }

        findChange(coins, amount, dp);
        
        return (dp[amount]==INT_MAX) ? -1 : dp[amount];
    }
};
