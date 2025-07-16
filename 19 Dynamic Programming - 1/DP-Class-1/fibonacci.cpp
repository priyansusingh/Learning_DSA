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
    
            if(dp[n] != -1){
                return dp[n];
            }
    
            dp[n] =  solveUsingMem(n-1,dp) +  solveUsingMem(n-2,dp);
            return dp[n];
        }
        int fib(int n) {
            // int ans = solveUsingRecursion(n);
            // return ans;
    
            vector<int> dp(n+1,-1);
           return solveUsingMem(n,dp);
        }
    };