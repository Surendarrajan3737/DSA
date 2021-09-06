// Similar to Longest Increasing Subsequence ; 
int maxSumIS(int nums[], int n)  
	{  
	    vector<int> MSIS(n);    
	    
	    for(int i=0;i<n;i++){
	        MSIS[i] = nums[i];          // Beacuse it is the maximum sum value of every each susequence
	    }
	    
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[j] < nums[i] && MSIS[i] < MSIS[j] + nums[i])
	                MSIS[i] = MSIS[j] + nums[i];    // Instead of storing subsequence i will store summ value 
	        }
	    }
	    
	    return *max_element(MSIS.begin(),MSIS.end());
	} 
