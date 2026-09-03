class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n));

        //base cases
        dp[0][0] = matrix[0][0];
        dp[0][1] = matrix[0][1];
        dp[0][2] = matrix[0][2];

        //bottom-up approach
        for(int i=1; i<m; i++){
            dp[i][0] = matrix[i][0] + max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = matrix[i][1] + max(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = matrix[i][2] + max(dp[i-1][0], dp[i-1][1]);
        }

        return max({dp[m-1][0], dp[m-1][1], dp[m-1][2]});
    }
};
