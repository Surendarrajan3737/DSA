class Solution {
public:
    string intToRoman(int num) {
        int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int n = sizeof(value)/sizeof(value[0]);
        
        string s;
        for(int i=0;i<n;i++){
            while(num >= value[i]){
                s += symbol[i];
                num -= value[i];
            }
        }
        return s;
    }
};
