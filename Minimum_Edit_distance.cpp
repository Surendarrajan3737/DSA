// dp problem 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
//              case 1 : s1 = ' ' and s2 has some string
                if(i == 0){
                    dp[i][j] = j;
                }
                
//              case 2 : s1 has some string and s2 = ' '
                else if(j == 0){
                    dp[i][j] = i;
                }
                
//              case 3 : value at s1 and s2 of i and j pointer are equal
                else if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];   //no operations needed to store the already matched value
                }
                
//              case 4 : value at s1 and s2 of i and j pointer are not equal
                else{
//      if they are not equal then adding one more operation to the previously computed opertion value
                    dp[i][j] = 1 + min({dp[i-1][j],     // Insert;
                                       dp[i][j-1],     // Delete;
                                       dp[i-1][j-1]});   // replace;
                }
            }
        }
        
        return dp[n][m];
    }
};
