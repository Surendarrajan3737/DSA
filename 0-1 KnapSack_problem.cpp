class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n+1,vector<int>(W+1));
        
        // Storing values in table using dp
        int i,w;
        for(i=0;i<=n;i++){
            for(w=0;w<=W;w++){
                
                if( i == 0 || w == 0){
                    dp[i][w] = 0;
                }
                else if(w < wt[i-1]){ // this indicates that the previous ele is more profitable
                    dp[i][w] = dp[i-1][w];
                }
                else if(w >= wt[i-1]){
                    dp[i][w] = max(dp[i-1][w],dp[i-1][w - wt[i-1]]+val[i-1]);
                }
            }
        }
        
        return dp[n][W];
    }
};
