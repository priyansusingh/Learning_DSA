#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


class Solution {
    public:
      int solveUsingRec(vector<int> &val, vector<int> &wt, int capacity, int index){
      
          // base case-> Single item
          if(index == 0){
              if(wt[0] <= capacity){
                  return val[0];
              }
              else{
                  return 0;
              }
          }
          
          //inc/exc
          int incl= 0;
          if(wt[index] <= capacity){
              incl = val[index] + solveUsingRec(val,wt,capacity-wt[index],index-1);
          }
          
          int excl = 0 + solveUsingRec(val,wt,capacity,index-1);
          int finalAns = max(incl,excl);
          
          return finalAns;
      }
      // 2 parameter change so 2d dp
      //top down appraoch
       int solveUsingMem(vector<int> &val, vector<int> &wt, int capacity, int index, vector<vector<int>> &dp){
      
          // base case-> Single item
          if(index == 0){
              if(wt[0] <= capacity){
                  return val[0];
              }
              else{
                  return 0;
              }
          }
          if(dp[capacity][index] != -1){
              return dp[capacity][index];
          }
          //inc/exc
          int incl= 0;
          if(wt[index] <= capacity){
              incl = val[index] + solveUsingMem(val,wt,capacity-wt[index],index-1,dp);
          }
          
          int excl = 0 + solveUsingMem(val,wt,capacity,index-1,dp);
          
          dp[capacity][index] = max(incl,excl);
          
          return  dp[capacity][ index];
      }
      
      int solveUsingTab(int capacity,vector<int> &wt, vector<int> &val){
          int n = val.size();
          //Step1
          vector<vector<int>> dp(capacity+1,vector<int>(n,0)); 
          //Step 2: Analyze base case
          for(int w = wt[0]; w<=capacity; w++){
              //bewakoof code
                  dp[w][0] = val[0];
          }
          
          //Step 3: parameter -> range -> reverse -> copy paste logic
          
          for(int weight = 0; weight <= capacity; weight++){
              for(int index = 1; index < n; index++){
          int incl= 0;
          if(wt[index] <= weight){
              incl = val[index] + dp[weight-wt[index]][index-1];
          }
          
          int excl = 0 + dp[weight][index-1];
          dp[weight][index] = max(incl,excl);
              }
         }
         return dp[capacity][n-1];
      }
      
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
       int capacity = W;
       int n = val.size();
       int index = n-1;
      //  return solveUsingRec(val,wt,capacity,index);
      
      //Step 1:
      //vector<vector<int>>dp(capacity+1,vector<int>(n,-1));
      
      return solveUsingTab(capacity,wt,val);
          
      }
  };