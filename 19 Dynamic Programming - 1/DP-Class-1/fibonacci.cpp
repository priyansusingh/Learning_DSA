#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int solveUsingRecursion(int n){
            if(n == 0){
                return 0;
            }
            if(n == 1){
                return 1;
            }
            int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);
            return ans;
        }
    
        int solveUsingMem(int n , vector<int> &dp){
            if(n == 0){
                return 0;
            }
            if(n == 1){
                return 1;
            }
            // Step 3: base case ke baad check if answer exists in dp array is exists then return
            if(dp[n] != -1){
                return dp[n];
            }
            // Step 2: dp array me ans store karo and return karo
            dp[n] =  solveUsingMem(n-1,dp) +  solveUsingMem(n-2,dp);
            return dp[n];
        }
    
        int solveUsingTabulation(int n){
          //Step 1: Create dp array
          vector<int> dp(n+1,-1);
    
          //Step 2: Analyze base cases paste and base case copy and update dp array
           if(n == 0){
                return 0;
            }
            if(n == 1){
                return 1;
            }
          dp[0] = 0;
          dp[1] = 1;
          
        //Step 3: Check parameter range and reverse it and run a loop over it
        //recursion n->0
        //loop 0 -> 1
        for(int i=2; i<=n; i++){
            //copy paste
            dp[i] =  dp[i-1] +  dp[i-2];
        }
         return dp[n];
        }
    
        int fib(int n) {
            // int ans = solveUsingRecursion(n);
            // return ans;
            // Step 1: find wether 1d/2d/3d dp and Create dp array and pass in function
        //     vector<int> dp(n+1,-1);
        //    return solveUsingMem(n,dp);
    
       return solveUsingTabulation(n);
        }
    };