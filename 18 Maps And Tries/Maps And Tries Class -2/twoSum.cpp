#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> map;
    
            // for(int index=0; index<nums.size(); index++){
            //     int value = nums[index];
            //     map[value] = index;
            // }
    
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