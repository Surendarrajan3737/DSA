// Time complexity = O(N) + O(N) + O(N)
// Space Complexity = O(3N);
// two pass method

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> v(n);
        vector<int> u(n);
        
//      this pass is for Left smaller
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            
            if(!s.empty())
                v[i] = s.top()+1;
            else
                v[i] = 0;
            
            s.push(i);
        }
        
//      Need to empty the stack
        while(!s.empty())   s.pop();
        
//      This pass is for right smaller
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            if(!s.empty())
                u[i] = s.top()-1;
            else
                u[i] = n-1;
            
            s.push(i);
        }
        
        int maxi = 0;
            
        for(int i=0;i<n;i++){
            maxi = max(maxi , heights[i] * (u[i] - v[i] + 1));
        }
        
        return maxi;
    }
};
