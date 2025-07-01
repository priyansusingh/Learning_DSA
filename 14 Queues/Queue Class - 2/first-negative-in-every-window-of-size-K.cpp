#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
    public:
      vector<int> firstNegInt(vector<int>& arr, int k) {
          // write code here
          deque<int> q;
          vector<int> ans;
          int n = arr.size();
          
          //Step 1: Process first window
          for(int i=0; i<k; i++){
              int element = arr[i];
              
              if(element < 0){
                  q.push_back(i);
              }
          }
          
          // Step 2: Process remaining window
          for(int i=k; i<n; i++){
              //ans store of previous window
              if(q.empty()){
                  ans.push_back(0);
              }
              else{
                  int index = q.front();
                  int element = arr[index];
                  ans.push_back(element);
              }
              //addition of new element
              if(!q.empty() && i-q.front() >= k){
                  q.pop_front();
              }
           
              int element = arr[i];
              if(element < 0){
                  q.push_back(i);
              }
          }
          //last window ka answer store karo
          if(q.empty()){
                  ans.push_back(0);
              }
              else{
                  int index = q.front();
                  int element = arr[index];
                  ans.push_back(element);
              }
              return ans;
      }
  };