// Using 2 pointers 
// i for iteration over space 
// j for iteration over words

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string result;
        int i=0;
        while(i<n){
            while(i<n && s[i] == ' ') i++;
            if(i>=n) break;
            int j=i+1;
            while(j<n && s[j] != ' ') j++;
            string w = s.substr(i,j-i);
            if(result.size() == 0) result = w;
            else result = w + " " + result;
            i = j+1;
        }
        
        return result;
    }
};
