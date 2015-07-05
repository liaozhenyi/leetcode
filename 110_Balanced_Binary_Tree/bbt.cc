/**********************************************************************

 Given a binary tree, determine if it is height-balanced.

 For this problem, a height-balanced binary tree is defined as a binary 
 tree in which the depth of the two subtrees of every node never differ by more than 1.

**********************************************************************/

class Solution {
public:

    int getDepthAndJudgeBalanced(TreeNode *node) {
        int leftDepth, rightDepth;
        
        if (NULL == node)
            return 0;
        leftDepth = getDepthAndJudgeBalanced(node->left);
        rightDepth = getDepthAndJudgeBalanced(node->right);
        
        if (-1 == leftDepth || -1 == rightDepth)
            return -1;
        if (leftDepth == rightDepth || leftDepth == rightDepth+1)
            return leftDepth+1;
        else if (leftDepth+1 == rightDepth)
            return rightDepth+1;
        else
            return -1;
    }

    // left is balanced, right is balanced, their depth differ less than 2.
    bool isBalanced(TreeNode *root) {
        int ans = getDepthAndJudgeBalanced(root);
        
        if (-1 == ans)
            return false;
        return true;
    }
    
};
