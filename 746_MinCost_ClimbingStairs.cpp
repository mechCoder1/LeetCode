class Solution
{
public:
    // bottom up, array solution
    int minCostClimbingStairs1(vector<int>& cost)
    {
        // cost[i] represents the cost to pay at i-th step
        
        int n = cost.size();
        
        //base case
        if(n==1) return cost[0];
        
        // dp[i] is the cost of reaching i-th step
        vector<int> dp(n);
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for (int i=2; i<n; i++)
        {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        
        // return dp[n]
        return min(dp[n-1],dp[n-2]) + 0;
    }
    
    // bottom up, equivalent two variable solution
    int minCostClimbingStairs2(vector<int>& cost)
    {
        // cost[i] represents the cost to pay at i-th step
        
        int n = cost.size();
        
        //base case
        if(n==1) return cost[0];
        
        int dp1 = cost[0];  // cost of reaching step # (n-1)
        int dp2 = cost[1];  // cost of reaching step # (n-2)
        
        for (int i=2; i<n; i++)
        {
            int dp0 = min(dp1, dp2) + cost[i]; // cost of reaching step # (n-0)
            
            dp1 = dp2; dp2 = dp0;
        }
        
        // return dp[n]
        return min(dp1,dp2) + 0;
    }
    
    // bottom up, two variable solution
    int minCostClimbingStairs(vector<int>& cost)
    {
        // cost[i] represents the cost to pay at i-th step
        
        int n = cost.size();
        
        // Nomenclature:
        // dp0 = cost of reaching step # (n-0)
        // dp1 = cost of reaching step # (n-1)
        // dp2 = cost of reaching step # (n-2)
        
        int dp1 = 0, dp2 = 0;
        
        for (int i=0; i<n; i++)
        {
            int dp0 = min(dp1, dp2) + cost[i];
            
            // march forward
            dp1 = dp2; dp2 = dp0;
        }
        
        // return cost of reaching step # n
        return min(dp1,dp2) + 0;
    }
};