class Solution {
    public:
        //Bottom-Up Approach or Rec + Mem
        int solveMem(vector<int>& nums, int n, int i, vector<int> &dp){
            //base case
            if( i >= n){
                return 0;
            }
    
            if(dp[i] != -1){
                return dp[i];
            }
    
            //include
            int includeAns = nums[i] + solveMem(nums, n, i+2,dp);
            //exclude
            int excludeAns = 0 + solveMem(nums, n, i+1,dp);
            dp[i] = max(includeAns, excludeAns);
    
            return dp[i];
        }
        //Top Down Approach or Tabulation method
        int solveTab(vector<int>& nums){
           int n = nums.size();
           vector<int> dp(n+2,0);
    
           for(int i=n-1; i>=0; i--){
            //include
            int includeAns = nums[i] + dp[i+2];
            //exclude
            int excludeAns = 0 + dp[i+1];
            dp[i] = max(includeAns, excludeAns);
           }
           return dp[0];
        }
    
        int solveUsingRec(vector<int>& nums, int n, int i){
            //base case
            if( i >= n){
                return 0;
            }
    
            //include
            int includeAns = nums[i] + solveUsingRec(nums, n, i+2);
            //exclude
            int excludeAns = 0 + solveUsingRec(nums, n, i+1);
            int finalAns = max(includeAns, excludeAns);
    
            return finalAns;
        }
    
        int solveUsingSO(vector<int>& nums){
           int n = nums.size();
           int next1 = 0;
           int next2 = 0;
           
           
           for(int i = n-1; i>=0; i--){
            int include = nums[i] + next2;
            int exclude = 0 + next1;
            int curr = max(include,exclude);
            //Shifting
            next2 = next1;
            next1 = curr;
           }
           return next1;
        }
    
        int rob(vector<int>& nums) {
            int i = 0;
            int n = nums.size();
            //int ans = solveUsingRec(nums, nums.size(), index);
            // vector<int> dp(n+1,-1);
            // return solveMem(nums,n,i,dp);
    
            // return solveTab(nums);
            return solveUsingSO(nums);
        }
    };