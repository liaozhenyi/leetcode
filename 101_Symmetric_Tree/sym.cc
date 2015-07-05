/**********************************************************************

 Given a binary tree, check whether it is a mirror of itself (ie, symmetric 
 around its center).

 For example, this binary tree is symmetric:
 
     1
    / \
   2   2
  / \ / \
 3  4 4  3
 But the following is not:
     1
    / \
   2   2
    \   \
    3    3
 Note:
 Bonus points if you could solve it both recursively and iteratively.

**********************************************************************/

class Solution {
public:

// method one: recurisively
    bool symmetric(TreeNode *a, TreeNode *b) {
        if (NULL == a && NULL == b)
            return true;
        if (NULL == a || NULL == b)
            return false;
        if (a->val != b->val)
            return false;
            
        return symmetric(a->left, b->right) && symmetric(a->right, b->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (NULL == root)
            return true;
        return symmetric(root->left, root->right);
    }

// method two: iteratively
    bool isSymmetric(TreeNode *root) {
        if (NULL == root)
            return true;
        
        std::stack<TreeNode *> stack1, stack2;
        TreeNode *left = root->left, *right = root->right;
        
        while (!stack1.empty() || NULL != left) {
            if ((!left && right) || (!right && left))
                return false;
            if (NULL == left) {
                left = stack1.top();
                stack1.pop();
                right = stack2.top();
                stack2.pop();
            }
            if (left->val != right->val)
                return false;
                
            if ((left->right && !right->left) || (!left->right && right->left))
                return false;
            if (left->right) {
                stack1.push(left->right);
                stack2.push(right->left);
            }
            left = left->left;
            right = right->right;
        }
        
        if (stack2.empty() && NULL == right)
            return true;
        return false;
    }
    
};
