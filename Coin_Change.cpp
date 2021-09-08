// Similar to Knapsack Problem

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size()+1,vector<int> (amount+1));
        
        for(int i=0;i<=coins.size();i++){
            for(int j=0;j<=amount;j++){
                if(i==0){   // No denominations
                    dp[i][j] = 1e5;  // Since we cannot able to attain the value in any means
                }
                else if(j == 0){   // This shows that amount == 0;
                    dp[i][j] = 0;
                }
                else if(j < coins[i-1]){
                    dp[i][j] = dp[i-1][j] ;
                }
                else{
                    // y coins i - 1 because arays are0 based indexing
                    dp[i][j] = min(dp[i-1][j],1 + dp[i][j-coins[i-1]]);
                }
            }
        }
        
        return dp[coins.size()][amount] >= 1e4 ? -1 : dp[coins.size()][amount];
    }
};
