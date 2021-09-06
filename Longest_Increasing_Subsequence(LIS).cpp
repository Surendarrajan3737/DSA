class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
//      T.C :    o(n2) approach
        
        vector<int> LIS(nums.size(),1);         // y 1 because each and every ele is a subsequence
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]  && LIS[j]+1 > LIS[i]){
                    LIS[i] = LIS[j] + 1;
                }
            }
        }
        
//         LIS[j] <= LIS[i]  ->  y this is beacuse we need to find the longest subsequence either it can be next to each other or the swquence until that element;
        
        return *max_element(LIS.begin(),LIS.end());
        
    }
};
