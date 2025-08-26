// leetcode 189. Rotate array
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        //step 1. reverse all
        reverse(nums.begin(), nums.end());
        //step 2. reverse first k
        reverse(nums.begin(), nums.begin()+k);
        //step 3. reverse first n-k
        reverse(nums.begin()+k, nums.end());
    }
};

int main(){
    vector<int> nums= {11,32,32,24,54,25,56,45};
    int k=3;
    Solution s;
    s.rotate(nums,k);

    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }cout<<endl;
}