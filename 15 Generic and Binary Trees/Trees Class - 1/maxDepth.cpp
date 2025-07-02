#include<iostream>
using namespace std;

class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(root == NULL){
                return 0;
            }
    
            int leftSubtreeHeight = maxDepth(root->left);
            int rightSubtreeHeight = maxDepth(root->right);
            int maxHeight = max(leftSubtreeHeight,rightSubtreeHeight);
            int totalHeight = maxHeight+1;
    
            return totalHeight;
        }
    };