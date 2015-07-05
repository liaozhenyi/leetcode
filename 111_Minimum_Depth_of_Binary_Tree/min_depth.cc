/**********************************************************************

 Given a binary tree, find its minimum depth.

 The minimum depth is the number of nodes along the shortest path from the 
 root node down to the nearest leaf node.

**********************************************************************/

class Solution {
public:

    static inline int getMin(int a, int b) {
        return a > b ? b : a;
    }

    int minDepth(TreeNode *root) {
        if (NULL == root)
            return 0;
            
        int leftDepth = INT_MAX, rightDepth = INT_MAX;
        
        if (NULL == root->left && NULL == root->right)
            return 1;
        if (root->left)
            leftDepth = minDepth(root->left);
        if (root->right)
            rightDepth = minDepth(root->right);
        
        return getMin(leftDepth, rightDepth) + 1;
    }
};
