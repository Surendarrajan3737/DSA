// one pass method;
class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<int> s;
        int n = a.size();
        int maxi = 0;
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i == n || a[i] < a[s.top()])){                         
                int height = a[s.top()];
                s.pop();
                int width;
                if(!s.empty()) 
                    width = i - s.top() -1;
                else 
                    width = i;
                
                maxi = max(maxi,height*width);
            }
            s.push(i);
        }
        return maxi;
    }
};
