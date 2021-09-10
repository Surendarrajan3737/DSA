class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int> (n+1));
        
        for(int i=0;i<=n;i++){ // This specifies there are no eggs to test
            dp[0][i] = 0;
            dp[1][i] = i;       // if only 1  egg then there wiuld be no possible way that i could use in all floors it can only be used in final floor
        }
        
        for(int j=0;j<=k;j++){  // This specifies that there are no floors to test;
            dp[j][0] = 0;
            dp[j][1] = 1;       // For only 1st floor there can be only one possible way
        }

        for(int i=2;i<=k;i++){
            for(int j=2;j<=n;j++){
                dp[i][j] = INT_MAX;
//              Varoius floors upto that current floor
                for(int x = 1;x<=j;x++){
                     // break or not break for each floor
                    int res;
                    res = 1 + max(dp[i-1][x-1] , dp[i][j-x]);
                    dp[i][j] = min(dp[i][j],res);
                }
            }
        }
        return dp[k][n];
    }
};
