// Using deque method:

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<n;i++){
            // Deletes the prvious window elements
            while(!dq.empty() && dq.front() == i-k)     
                dq.pop_front();
            
            // Deletes the small element to maintain the decreasing fashion of order in deque;
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            // The front element should the maximum
            if(i >= k-1) ans.push_back(nums[dq.front()]);  
        }
        
        return ans;
    }
};
