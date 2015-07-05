/**********************************************************************

 Given a binary tree, find its maximum depth.

 The maximum depth is the number of nodes along the longest path from the 
 root node down to the farthest leaf node.

**********************************************************************/

class Solution {
public:

    static inline int getMax(int a, int b) {
        return a > b ? a : b;
    } 

    int maxDepth(TreeNode *root) {
        if (NULL == root)
            return 0;

        int left, right;
        left = maxDepth(root->left);
        right = maxDepth(root->right);
        
        return getMax(left, right)+1;
    }
    
};
