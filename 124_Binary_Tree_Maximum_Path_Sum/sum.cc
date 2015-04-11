/**********************************************************************

 Given a binary tree, find the maximum path sum.

 The path may start and end at any node in the tree.
 
 For example:
 Given the below binary tree,
 
        1
       / \
      2   3
 Return 6.

**********************************************************************/

class Solution {
public:

    static inline int getMax(int a, int b, int c) {
        if (a > b) 
            return a > c ? a : c;
        else
            return b > c ? b : c;
    }
    
    int maxPath(TreeNode *cur, int &toleaf) {
        if (NULL == cur) {
            toleaf = 0;
            return INT_MIN;
        }
        
        int leftMaxpath, rightMaxpath, leftToleaf, rightToleaf;
        leftMaxpath = maxPath(cur->left, leftToleaf);
        rightMaxpath = maxPath(cur->right, rightToleaf);
        
        toleaf = cur->val + getMax(leftToleaf, rightToleaf, 0);
        int centerMaxpath = cur->val + (leftToleaf > 0 ? leftToleaf: 0) + (rightToleaf > 0 ? rightToleaf : 0);
        
        return getMax(leftMaxpath, rightMaxpath, centerMaxpath);
    }

    int maxPathSum(TreeNode *root) {
        int toleaf;
        return maxPath(root, toleaf);
    }
};
