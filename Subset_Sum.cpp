    bool isSubsetSum(int N, int arr[], int sum){
        vector<vector<bool>> dp(N+1,vector<bool> (sum+1));
        
        for(int i=0;i<=N;i++){
            for(int j=0;j<=sum;j++){
                
                if(j == 0)  // sum == 0
                    dp[i][j] = true;
                    
                else if(i == 0) // empty set or array
                    dp[i][j] = false;
                    
                else if(j < arr[i-1])  // we can able to attain it with the previous itself
                    dp[i][j] = dp[i-1][j];
                    
                else{           // we are able to attain it by either including our curretn ele or not
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                }
            }
        }
        
        return dp[N][sum];
    }
