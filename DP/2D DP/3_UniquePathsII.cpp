class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int obs_fir_row = 0;
        int i = 0;
        while(i < n){
            if(obstacleGrid[0][i] != 1){
                dp[0][i] = 1;
            }
            else{
                obs_fir_row = 1;
                break;
            }
            i++;
        }
        while(i < n && obs_fir_row == 1){
            dp[0][i] = 0;
            i++;
        }
        int obs_fir_col = 0;
        int j = 0;
        while(j < m){
            if(obstacleGrid[j][0]!=1){
                dp[j][0] = 1;
            }
            else{
                obs_fir_col = 1;
                break;
            }
            j++;
        }

        while(j < m){
            dp[j][0] = 0;
            j++;
        }
       

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
