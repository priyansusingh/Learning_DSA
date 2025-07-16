#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode{
    public:
    char value;
    unordered_map<int,TrieNode*> children;
    bool isTerminal;

    TrieNode(char data){
        value = data;
        isTerminal = false;
    }

};

void insertIntoTrie(TrieNode* root, string word){
    //base case -> jab word khatam ho gaya ho
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    TrieNode* child;     // child ka variable creation
    
    if(root->children.count(ch) == 1){
        child = root->children[ch]; 
    }
    else{
        child = new TrieNode(ch);
        root->children[ch] = child;
    }
    
    insertIntoTrie(child,word.substr(1));
}


int main(){
    

    return 0;
}