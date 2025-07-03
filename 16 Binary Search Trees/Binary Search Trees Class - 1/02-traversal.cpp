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

int getMin(Node* root){
   if(root == NULL){
    return -1;
   }
   while(root->left != NULL){
    root = root->left;
   }
   return root->data;
}

int getMax(Node* root){
    if(root == NULL){
     return -1;
    }
    while(root->right != NULL){
     root = root->right;
    }
    return root->data;
 }


void preOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data <<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data <<" ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data <<" ";
}
int main(){
    Node* root = NULL;
    createTree(root);
    cout<< "Level order: ";
    leveOrderTraversal(root);
    cout<<endl;
    cout<< "in order: ";
    inOrderTraversal(root); //InOrder Traversal of a BST is always sorted
    cout<<endl;
    cout<< "pre order: ";
    preOrderTraversal(root);
    cout<<endl;
    cout<< "post order: ";
    postOrderTraversal(root);
    cout<<endl;
    cout<< "Min Element: "<< getMin(root) << endl;
    cout<< "Max Element: "<< getMax(root) << endl;

    return 0;
}