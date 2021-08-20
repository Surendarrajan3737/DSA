class Solution{
  public:
    int atoi(string s) {
        int i=0;
        int ans = 0;
        int sign = 1;
        while(s[i] == ' '){
            i++;
        }
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        while(s[i] && s[i] != ' '){
            int x = s[i] - '0';
            if(x>=0 && x<=9){
                ans = ans * 10 + x;
            }
            else 
                return -1;
            i++;
        }
        return ans*sign;
    }
};
