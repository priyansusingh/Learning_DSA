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

bool searchTrie(TrieNode* root, string word){
    //base case
    if(word.length() == 0){
        return root->isTerminal;
    }
    // 1 case
    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()){
       child = root->children[ch];
    }
    else{
        //abscent
        return false;
    }

    bool recursionKaAns = searchTrie(child, word.substr(1));
    return recursionKaAns;
}

void deleteWord(TrieNode* root, string word){
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()){
        //found
        child = root->children[ch];
    }
    else{
        return;
    }
    deleteWord(child,word.substr(1));
}

int main(){
    TrieNode* root = new TrieNode('-');    
    insertIntoTrie(root,"cover");
    insertIntoTrie(root,"car");
    insertIntoTrie(root,"care");
    insertIntoTrie(root,"snake");
    insertIntoTrie(root,"sundari");
    insertIntoTrie(root,"extremelyWell");
    insertIntoTrie(root,"coward");
    insertIntoTrie(root,"tag");
    insertIntoTrie(root,"take");
    insertIntoTrie(root,"took");
    insertIntoTrie(root,"selfobsessed");

    bool ans = searchTrie(root,"cover");
    
    if(ans){
      cout<<"Found"<<endl;
    }
    else{
      cout<<"Not Found"<<endl;
    }
    deleteWord(root,"cover");

    ans = searchTrie(root,"cover");
    
    if(ans){
      cout<<"Found"<<endl;
    }
    else{
      cout<<"Not Found"<<endl;
    }
    
    return 0;
}