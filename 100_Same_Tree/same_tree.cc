/**********************************************************************

 Given two binary trees, write a function to check if they are equal or not.

 Two binary trees are considered equal if they are structurally identical 
 and the nodes have the same value.

**********************************************************************/

class Solution {
public:

    bool isSameTree(TreeNode *p, TreeNode *q) {
        std::stack<TreeNode *> stack1, stack2;
        TreeNode *cur1 = p, *cur2 = q;
        
        while (NULL != cur1 || !stack1.empty()) {
            if ((cur1 && !cur2) || (!cur1 && cur2))
                return false;
            if (!cur1) {
                cur1 = stack1.top();
                stack1.pop();
                cur2 = stack2.top();
                stack2.pop();
            }
            
            if (cur1->val != cur2->val)
                return false;
            
            if ((!cur1->right && cur1->right) || (cur1->right && !cur2->right))
                return false;
            if (cur1->right) {
                stack1.push(cur1->right);
                stack2.push(cur2->right);
            }
            cur1 = cur1->left;
            cur2 = cur2->left;
        }
        if (!cur2 && stack2.empty())
            return true;
        return false;
    }
    
};
