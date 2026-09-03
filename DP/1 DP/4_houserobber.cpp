class Solution {
public:
    // int f(int n, vector<int>& dp, vector<int>&nums){
    //     if(n==0) return dp[n] = nums[0];
    //     if(n==1) return dp[n] = max(nums[0], nums[1]);
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     return dp[n] = max(f(n-1, dp, nums), nums[n] + f(n-2, dp, nums));
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[n-1];
    }
};
