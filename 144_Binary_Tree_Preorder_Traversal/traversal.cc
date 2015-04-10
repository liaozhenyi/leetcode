/**********************************************************************

 Given a binary tree, return the preorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
 return [1,2,3].

**********************************************************************/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        TreeNode *cur = root;
        vector<int> traversal;
        
        while (NULL != cur || !nodeStack.empty()) {
            if (NULL == cur) {
                cur = nodeStack.top();
                nodeStack.pop();
            }
            traversal.push_back(cur->val);
            if (cur->right)
                nodeStack.push(cur->right);
            cur = cur->left;
        }
        
        return traversal;
    }
    
private:
    std::stack<TreeNode *> nodeStack;
};
