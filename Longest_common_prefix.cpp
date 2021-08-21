// Time Complexity = O(nlog n)

class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string s = "";
        if(str.size() == 0) return s;
        int n = str.size();
        sort(str.begin(),str.end());        // nlog n  
        
        int mini = min(str[0].size(),str[n-1].size());
        
        for(int i=0;i<mini;i++){            //  n
            if(str[0][i] != str[n-1][i])
                return s;
            else
                s += str[0][i];
        }
        return s;
    }
};
