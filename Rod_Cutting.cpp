// Tabulation Method

#include <bits/stdc++.h>

using namespace std;

int Max_profit(vector<int> &price,int Max_len){
    vector<vector<int>> dp(price.size()+1,vector<int> (Max_len + 1));

    for(int i=0;i<=price.size();i++){
        for(int j=0;j<=Max_len;j++){
            if(i == 0)
                dp[0][i] = 0;
            else if(j == 0)
                dp[i][0] = 0;
            else{
                if(j<i){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],price[i-1]+dp[i][j-i]);
                }
            }
        }
    }

    return dp[price.size()][Max_len];

}

int main()
{
    int Max_len = 8;
    vector<int> price{ 1, 5, 8, 9, 10, 17, 17, 20 };
    cout << "The Max profit is : " <<Max_profit(price,Max_len);
    return 0;
}


// T.C -> O(N*M)
// S.C ->O(N*M)
