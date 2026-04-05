class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpFirst(n,0);
        vector<int> dpLast(n,0);

        dpFirst[0] = nums[0];
        dpFirst[1] = max(nums[0],nums[1]);

        dpLast[0] = 0;
        dpLast[1] = nums[1];

        // DpFirst : picking 1 element and not picking last element
        for(int i=2; i<n-1; i++) {
            dpFirst[i] = max(nums[i] + dpFirst[i-2], dpFirst[i-1]);
        }
        int maxDpFirst = max(dpFirst[n-1], dpFirst[n-2]);

        //DpLast : picking last element and not the first element
        for(int i=2; i<n; i++) {
            dpLast[i] = max(nums[i] + dpLast[i-2], dpLast[i-1]);
        }
        int maxDpLast = max(dpLast[n-1], dpLast[n-2]);

        return max(maxDpFirst, maxDpLast);
    }
};
