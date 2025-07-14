#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> m;
    
            for(int i=0; i<strs.size(); i++){
                string original = strs[i];
                string copy = strs[i];
                sort(copy.begin(),copy.end());
                m[copy].push_back(original);
            }
    
            vector<vector<string>> ans;
            for(auto i : m){
                ans.push_back(i.second);
            }
    
            return ans;
        }
    };