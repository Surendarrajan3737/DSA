// c[i][j] = min(c[i][k] + c[k+1][j] + d[i-1] * d[k] * d[j])  where  i <= k < j; 
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int> (N));      // Since N is no of matrix + 1;
        
        for(int i=1;i<N;i++){
            dp[i][i] = 0;// we know that dp[1][1] = 0; since it is a single matrix the minimum multiply needed is 0
        }
        
        int j;
        
        for(int L = 2; L<N ;L++){        // y beacuse we need to compute the smaller difference first i.e 2-1 = 1 ans similarly 3-2;
            for(int i=1; i<N-L+1 ;i++){  // see matrix    
                j = i+L-1;               // computed for every row   
                dp[i][j] = INT_MAX;     // done to find the min
                for(int k=i;k<j;k++){   // for every value of k we need to find minim mltiplication
                    dp[i][j] = min(dp[i][j],(dp[i][k] + dp[k+1][j]) + (arr[i-1] * arr[k] * arr[j]));    // see my formula
                }
            }
        }
        
        return dp[1][N-1];    // definitely it is gona be the least multiplication needed
    }
