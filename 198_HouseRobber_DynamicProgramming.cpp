class Solution {
private:
        
public:
    // forward method:
    int rob_fw(vector<int>& nums)
    {   
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        //initialize memo:
        vector <int> memo(n, -1);
        
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<n; i++)
        {
            memo[i] = max(nums[i]+memo[i-2], memo[i-1]);
        }
        
        return memo[n-1];
    }
    
    // backward method:
    int rob_bw(vector<int>& nums)
    {   
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        //initialize memo, note the size:
        vector <int> memo(n+1, -1);
        
        memo[n] = 0;
        memo[n-1] = nums[n-1];
        
        for(int i=n-2; i>=0; i--)
        {
            //              rob i              skip i
            memo[i] = max(nums[i]+memo[i+2], memo[i+1]);
        }
        
        return memo[0];
    }
    
    // forward method, optimized:
    int rob_fw_opt(vector<int>& nums)
    {   
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        //initialize memo:
        int memo0, memo1, memo2=-1;
        
        memo0 = nums[0];
        memo1 = max(nums[0], nums[1]);
        if(n==2) return memo1;
        
        for(int i=2; i<n; i++)
        {
            memo2 = max(nums[i]+memo0, memo1);
            memo0 = memo1;
            memo1 = memo2;
        }
        
        return memo2;
    }
    
    // backward method, optimized:
    int rob(vector<int>& nums)
    {   
        int n = nums.size();
        
        //initialize memo:
        int memo0, memo1, memo2;
        
        memo0 = 0;
        memo1 = nums[n-1];  // last nums
        
        for(int i=n-2; i>=0; i--)
        {
            memo2 = max(nums[i]+memo0, memo1);
            memo0 = memo1;
            memo1 = memo2;
        }
        
        return memo2;
    }
    
};



// Recursive Method:
class Solution1 {
private:
    vector<int> memo;
    
public:
    int rob(vector<int>& nums)
    {
        //initialize memo:
        vector <int> memo1(nums.size(), -1);
        memo = memo1;
        
        // call recursive function:
        return robFrom(0, nums);
    }
    
    int robFrom(int i, vector<int>& nums)
    {
        if(i >= nums.size())
        {
            return 0;
        }
        
        if (memo[i] == -1)
        {
            memo[i] = max(nums[i] + robFrom(i+2,nums), robFrom(i+1,nums));
            return memo[i];
        }
        else
            return memo[i];
    }
};