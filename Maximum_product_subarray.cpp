// Using DP -> storing the previous values that helps us to find the product
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int res = INT_MIN;          // Since we have negative values in the array;
        
        int max_product = 1;
        int min_product = 1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0){
                swap(max_product,min_product);          // To maintain the max and min values;
            }
            // if ele is 0 then reset to the next number ;
            // [3,0,7]
            max_product = max(max_product*nums[i] , nums[i]);   // 3*0 = max(3*0,0) -> max(0*7,7)
            min_product = min(min_product*nums[i] , nums[i]);
                
            res = max(res,max_product);
        }
        
        return res;
    }
};
