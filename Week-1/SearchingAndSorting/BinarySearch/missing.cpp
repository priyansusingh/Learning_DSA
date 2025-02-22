#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Leetcode : 268
class Solution {
public:
    int missingNumber(vector<int>& arr) {
       sort(arr.begin(), arr.end()); // Step 1: Sort the array 
       int n = arr.size(); 
       int s = 0, e  = n-1;
       int mid = s + (e-s)/2;
       int ans = -1;
       while( s <= e){
        if(arr[mid] - mid == 0){
            ans = arr[mid] + 1; // Store an answer and compute next in right direction
            s = mid + 1;
        }
        if(arr[mid] - mid == 1){
          ans = mid;       // Store the current index and compute next in left direction
          e = mid - 1;
        }
        mid = s + (e-s)/2;      
       }

      return ans;
    }
};