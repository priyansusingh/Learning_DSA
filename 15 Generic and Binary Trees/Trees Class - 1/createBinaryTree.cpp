#include<iostream>
using namespace std;

class Node{
   public:
   int data;
   Node* left;
   Node* right;

   Node(int value){
    this->data = value;
    left = NULL;
    right = NULL;
   }

};

Node* createTree(){
    cout << "Enter the value for node: " <<endl;
    int value;
    cin >> value;
    
    if(value == -1){
        return NULL;
    }
    else{
        Node* root = new Node(value);
        // 1 case maine kar liya baaki left aur right ke liye recursion sambhalega
        cout<<"Adding left child for "<< value << endl;
        root->left = createTree();
        cout <<"Adding rigth child for "<< value <<endl;
        root->right = createTree();
        
        return root;
    }
}


int main(){
  Node* root;
  root = createTree();

  return 0;
}