class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Solution 1 : 
        vector<int> ans;
        multiset<int> s;
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

        // Solution 2 -- not working yet 16/20 passed
        // vector<int> ans;
        // int maxi1 = -10001;
        // int maxi2 = -10001;
        // int maxi1ind = -1;
        // int maxi2ind = -1;
        // for(int i=0;i<k; i++) {
        //     if(nums[i] >= maxi1) {
        //         maxi2 = maxi1;
        //         maxi2ind = maxi1ind;
        //         maxi1 = nums[i];
        //         maxi1ind = i;
        //     }
        //     else if (nums[i] >= maxi2){
        //         maxi2 = nums[i];
        //         maxi2ind = i;
        //     }
        // }
        // ans.push_back(maxi1);
        // int len = nums.size();
        // for(int i=1; i<len-k+1;i++) {
        //     cout << "i = " << i << endl;
        //     // deleting an element
        //     if(nums[i-1] == maxi1) {
        //         maxi1 = maxi2;
        //         maxi1ind = maxi2ind;
        //         maxi2 = -10001;
        //         // check from i to i+k-1 and update the 2nd max
        //         for(int j = i; j<i+k-1; j++){
        //             if(nums[j] > maxi2 && j!=maxi1ind){
        //                 maxi2 = nums[j];
        //                 maxi2ind = j;
        //             }
        //         }
        //     }
        //     // adding new element
        //     if(nums[i+k-1] >= maxi1) {
        //         maxi2 = maxi1;
        //         maxi2ind = maxi1ind;
        //         maxi1 = nums[i+k-1];
        //         maxi1ind = i+k-1;
        //     }
        //     if (nums[i+k-1] > maxi2){
        //         maxi2 = nums[i+k-1];
        //         maxi2ind = i+k-1;
        //     }
        //     cout << maxi1 << " " << maxi2 << endl;
        //     cout << maxi1ind << " " << maxi2ind << endl;
        //     ans.push_back(maxi1);
        // }
        // return ans;
    }
};
