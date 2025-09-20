#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> map;
       
       for(int i=0; i<nums.size(); i++){
           int currElement = nums[i];
           int valueToFind = target-currElement;
           
           if(map.find(valueToFind) != map.end()){
               return {i,map[valueToFind]};
           }
           map[currElement] = i;
       }
       
       return {-1,-1};
    }
};

int main() {
   Solution s;
   vector<int>nums = {2,7,11,15};
   int target = 9;
   vector<int> ans = s.twoSum(nums,target);
   
   for(int x:ans){
       cout<<x<<" ";
   }cout<<endl;

    return 0;
}