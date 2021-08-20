// Time comp = O(N);
// Space Complexity = O(1);

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int n = s.size();
        int i=0;
        int sum = 0;
        while(i<n){
            if(m[s[i]] >= m[s[i+1]])
                sum += m[s[i++]];
            else{
                sum += (m[s[i+1]] - m[s[i]]);
                i+=2;
            }
        }
        
        return sum;
    }
};
