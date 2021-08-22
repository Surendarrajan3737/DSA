class Solution {
public:
    int compareVersion(string version1, string version2) {
//      Counting no of dots equal;
        int d1 = count(version1.begin(),version1.end(),'.');
        int d2 = count(version2.begin(),version2.end(),'.');
        
//      Finding the differnce
        int dif = abs(d1-d2);
        
//      Making equal no of dots
        while(dif--){
            if(d1>d2){
                version2 += ".0";
            }
            else{
                version1 += ".0";
            }
        }
        
//      Replacing '.' with ' ' empty string
        replace(version1.begin(),version1.end(),'.',' ');
        replace(version2.begin(),version2.end(),'.',' ');
    
        // strinfstream v1("1 2 3") x = 1 , y = 3 , z = 3;

//      This helps us to break the word;
        stringstream s1(version1);
        stringstream s2(version2);
        
        int n1,n2;
        while(s1 >> n1 && s2 >> n2){
            if(n1 > n2) return 1;
            else if(n2 > n1) return -1; 
        }
        
        return 0;
    }
};
