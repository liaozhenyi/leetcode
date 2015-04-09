/**********************************************************************

 Given a binary tree, return the postorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
 return [3,2,1].

**********************************************************************/

class Solution {
public:
    
    /*
     * Method One: recursive
     */
    vector<int> postorderTraversal(TreeNode *root) {
        if (NULL == root)
            return vector<int>();
        if (NULL == root->left && NULL == root->right)
            return vector<int>(1, root->val);
            
        vector<int> traversal, left, right;
        left = postorderTraversal(root->left);
        right = postorderTraversal(root->right);
        traversal = left;
        traversal.insert(traversal.end(), right.begin(), right.end());
        traversal.push_back(root->val);
        
        return traversal;
    }

    /*
     * Method Two: iteratively
     */
    void pushStack(TreeNode *root) {
        TreeNode *cur = root;
        
        while (NULL != cur) {
            nodeStack.push(cur);
            if (NULL != cur->left)
                cur = cur->left;
            else if (NULL != cur->right)
                cur = cur->right;
            else
                break;
        }
    }

    vector<int> postorderTraversal(TreeNode *root) {
        TreeNode *cur;
        vector<int> traversal;
        
        pushStack(root);
        while (!nodeStack.empty()) {
            cur = nodeStack.top();
            nodeStack.pop();
            traversal.push_back(cur->val);
            if (!nodeStack.empty()) {
                // if cur is the left child of its parent, before
                // traverse its parent, traverse its sibling first
                if (cur == nodeStack.top()->left)
                    pushStack(nodeStack.top()->right);
            }
        }
        
        return traversal;
    }
    
private:
    std::stack<TreeNode *> nodeStack;
};
