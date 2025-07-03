#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        left = NULL;
        right = NULL;
    }
};
//O(log(N))
Node* buildBST(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    if(val < root->data){
       root->left = buildBST(root->left,val);
    }
    else{
        root->right = buildBST(root->right,val);
    }
   return root;
}

void createTree(Node* &root){
   int val;
   cout<< "Enter value for Node: "<<endl;
   cin>>val;

   while(val != -1){
    root = buildBST(root,val);
    cout<< "Enter value for Node: "<<endl;
    cin>>val;
   }
}

void leveOrderTraversal(Node* root){
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
        cout<< front->data <<" ";
        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }
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
int main(){
    Node* root = NULL;
    createTree(root);
    leveOrderTraversal(root);
    inOrderTraversal(root); //InOrder Traversal of a BST is always sorted
    preOrderTraversal(root);
    postOrderTraversal(root);
    return 0;
}