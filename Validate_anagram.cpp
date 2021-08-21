class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        
        if(s.size() != t.size()) return false;
        
        for(int i=0;i<s.size();i++){
            v[s[i]-97]++;
        }
        
        for(int i=0;i<t.size();i++){
            v[t[i]-97]--;
            if(v[t[i]-97] < 0)
                return false;
        }
        
        return true;
    }
};
