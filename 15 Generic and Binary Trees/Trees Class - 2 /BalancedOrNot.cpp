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
        int getHeight(TreeNode* root){
            if(root == NULL) return 0;
            
            int lh = getHeight(root->left);
            int rh = getHeight(root->right);
            int heightAns = max(lh,rh) + 1;
    
            return heightAns;
        }
        bool isBalanced(TreeNode* root) {
            if(root == NULL){
                return true;
            }
            int left = getHeight(root->left);
            int right = getHeight(root->right);
            int absDiff =  abs(left-right);
            bool status = absDiff <= 1;
    
            bool leftSubTree = isBalanced(root->left);
            bool rightSubTree = isBalanced(root->right);
    
            if(status && leftSubTree && rightSubTree){
                return true;
            }
            else{
                return false;
            }
        }
    };