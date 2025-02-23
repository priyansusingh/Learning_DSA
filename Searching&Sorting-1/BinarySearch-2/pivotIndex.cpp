#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    int getPivotIndex(vector<int> nums){
       int n = nums.size();
       int s = 0, e = n-1;
       int mid = s + (e-s)/2;

       while( s <= e){
        if(s == e){ // Array me ek hi element hai
            return s;
        }
        if( mid + 1 < n && nums[mid] > nums[mid+1]){
        return mid;
       }
       if( mid - 1 >= 0 && nums[mid] < nums[s]){
        e = mid - 1; // left me jao, answer wahi hai
       }
       else{
        s = mid + 1; // right me jao
       }
       mid = s + (e-s)/2;  // mid ko update karo
       }
       return -1;
    }
    int binarySearch(vector<int> nums, int s, int e, int target){
        int n = nums.size();
        int mid = s + (e-s)/2;

        while(s <= e){
            if( nums[mid] == target){
                return mid;
            }
            if( target > nums[mid]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotIndex = getPivotIndex(nums);
        int n = nums.size();
        // Y fir answer Line B me hoga
        // 0 to pivotIndex
        if( target < nums[0]){ 
            int ans = binarySearch(nums, pivotIndex+1, n-1, target);
            return ans;
        }
    
        // Ya to answer Line A me hoga
        // 0 to pivotIndex;
        else{
            int ans = binarySearch(nums, 0, pivotIndex, target);
            return ans;
        }
        
        return -1;
    }
};