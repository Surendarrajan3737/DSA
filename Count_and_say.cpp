class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";
        
        string s = "11";
        for(int i=3;i<=n;i++){
            s = s+'&';
            int cnt=1;
            string tmp="";
            cout << s.size();
            for(int j=1;j<s.size();j++){
                if(s[j] == s[j-1]){
                    cnt++;
                }
                else{
                    tmp += to_string(cnt);
                    tmp += s[j-1];
                    cnt = 1;
                }
            }
            s = tmp;
        }
        return s;
    }
};
