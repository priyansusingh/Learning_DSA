#include<iostream>
#include<unordered_map>
using namespace std;

// leetcode 2325. Decode the Message
class Solution {
public:
    string decodeMessage(string key, string message) {
        //step 1 : create mapping
        unordered_map<char,char> mapping;
        char space = ' ';
        mapping[space] = space;
        char start = 'a';
        int index=0;
        while(start<= 'z' && index < key.length()){
            char keyCurrrentCharacter = key[index];
            //start-> mapping abcd...
            //mapping: keyCurrentCharacter->alphabet
            if(mapping.find(keyCurrrentCharacter) != mapping.end()){
                //currentCharacter already has a mapping: just move to next char in key
                index++;
            }
            else{
                //currentCharacter is mapping 
                mapping[keyCurrrentCharacter] = start; 
                start++; 
                index++;
            }
        }
        //step 2: use mapping to decode msg
        string ans = "";
        for(int i=0; i<message.length();i++){
            char msgCharacter = message[i];
            char mappedCharacter = mapping[msgCharacter];
            ans.push_back(mappedCharacter);
        }
        return ans;
    }
};

int main(){
    string message = "the quick brown fox jumps over the lazy dog";
    string key = "vkbs bs t suepuv";

    Solution s;
    string ans = s.decodeMessage(message,key);
    cout << ans <<" ";

    return 0;
}