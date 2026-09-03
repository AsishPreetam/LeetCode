class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));

        //base cases
        int first_row_sum = 0;
        for(int j = 0; j < n; j++){
            first_row_sum += grid[0][j];
            dp[0][j] = first_row_sum;
        }
        int first_col_sum = 0;
        for(int i = 0; i < m; i++){
            first_col_sum += grid[i][0];
            dp[i][0] = first_col_sum;
        }

        //building the dp
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);
            }
        }
        
        return dp[m-1][n-1];
    }
};
