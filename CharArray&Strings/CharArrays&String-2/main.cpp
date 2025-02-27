#include<iostream>
using namespace std;

// 1047. Remove All Adjacent Duplicates In String

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string ans = ""; //empty string initialization
        for(int i=0; i<n; i++){
            char currCharacter = s[i];//current character from original string
            if(ans.empty()){ 
                // checking if string is empty or not
                //if yes then pop last element from ans string using back() 
                ans.push_back(currCharacter);
            }
            else if( currCharacter == ans.back()){
                // agar current character aur ans string ka last character
                // same ho to ans string ka last element remove karo
                // pop_back() ka use karke
                ans.pop_back();
            }
            else if( currCharacter != ans.back()){
                // agar different hai to push kardo current character ko
                ans.push_back(currCharacter);
            }
        }
        return ans;
    }
};