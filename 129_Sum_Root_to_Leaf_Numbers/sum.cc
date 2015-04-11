/**********************************************************************

 Given a binary tree containing digits from 0-9 only, each root-to-leaf 
  path could represent a number.

 An example is the root-to-leaf path 1->2->3 which represents the number 123.
 
 Find the total sum of all root-to-leaf numbers.
 
 For example,
 
     1
    / \
   2   3
 The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13.
 
 Return the sum = 12 + 13 = 25.

**********************************************************************/

class Solution {
public:

    int traversal(TreeNode *cur, int num) {
        int leftValue, rightValue;
        if (NULL == cur)
            return 0;

        if (NULL == cur->left && NULL == cur->right)
            return num*10 + cur->val;

        leftValue = traversal(cur->left, num*10 + cur->val);
        rightValue = traversal(cur->right, num*10 + cur->val);
        return leftValue + rightValue;
    }

    int sumNumbers(TreeNode *root) {
        return traversal(root, 0);
    }
    
};
