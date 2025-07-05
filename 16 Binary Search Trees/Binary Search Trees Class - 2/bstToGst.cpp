/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        void storeInorder(TreeNode* root, vector<int> &inorder){
            if(root == NULL) return;
            storeInorder(root->left,inorder);
            inorder.push_back(root->val);
            storeInorder(root->right,inorder);
        }
        void updateTree(TreeNode* root, vector<int> inorder, int &index){
            if(root == NULL) return;
            updateTree(root->left,inorder,index);
            root->val = inorder[index];
            index++;
            updateTree(root->right,inorder,index);
        }
        TreeNode* bstToGst(TreeNode* root) {
            // Step 1: Store inorder
            vector<int> inorder;
            storeInorder(root,inorder);
            // step 2: update inorder
            int n = inorder.size();
            
            for(int i=n-1; i>=0; i--){
                int currVal = inorder[i];
                int nextVal = 0;
    
                if( i+1 < n){
                    nextVal = inorder[i+1];
                }
                int sum = currVal + nextVal;
                inorder[i] = sum;
            }
            // update tree using inorder
           int index = 0;
           updateTree(root,inorder,index);
           return root;
        }
    };