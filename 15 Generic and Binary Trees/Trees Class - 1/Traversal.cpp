#include<iostream>
#include<queue>
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
    //cout << "Enter the value for node: " <<endl;
    int value;
    cin >> value;
    
    if(value == -1){
        return NULL;
    }
    else{
        Node* root = new Node(value);
        // 1 case maine kar liya baaki left aur right ke liye recursion sambhalega
        //cout<<"Adding left child for "<< value << endl;
        root->left = createTree();
        //cout <<"Adding rigth child for "<< value <<endl;
        root->right = createTree();
        
        return root;
    }
}

void preOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    //NLR
    //N -> current node
    cout << root->data <<" ";
    //L -> left subtree
    preOrderTraversal(root->left);
    //R -> right subtree
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // LNR
    //L
    inOrderTraversal(root->left);
    //N
    cout << root->data <<" ";
    //R
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    //LRN
    //L
    postOrderTraversal(root->left);
    //R
    postOrderTraversal(root->right);
    //N
    cout << root->data <<" ";
}

void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout << front->data<<" ";
        if(front->left != NULL){
        q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }
    }
    
}

int main(){
  Node* root;
  root = createTree();
  // 10 50 40 -1 -1 -1 30 20 -1 -1 -1
  levelOrderTraversal(root);
//   preOrderTraversal(root);
//   cout<<endl;
//   inOrderTraversal(root);
//   cout<<endl;
//   postOrderTraversal(root);
  return 0;
}