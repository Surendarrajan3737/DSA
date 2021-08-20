//  Using Dynamic programing with tabulation method/technique;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0 ) return s;
        bool tab[n][n];         // Tabulation 
        
        memset(tab,0,sizeof(tab));            
        
        // For middle diagonal index;
        int maxlength = 1;
        int start = 0;
        
        for(int i=0;i<n;i++){
            tab[i][i] = 1;
        }
        
        // for size 2;
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                tab[i][i+1] = 1;
                start = i;
                maxlength = 2;
            }
        }
        
        // For size > 2;
        for(int k=3;k<=n;k++){   // This is for length
            for(int i = 0;i<n-k+1;i++){    // this is for iterator
                int j = i+k-1;      // This is for length of the substring i.e ending
                
                if(s[i] == s[j] && tab[i+1][j-1] == 1){
                    tab[i][j] = 1;
                    
                    if(k > maxlength){
                        maxlength = k;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start,maxlength);
    }
};
