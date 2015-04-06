/**********************************************************************

 Implement an iterator over a binary search tree (BST). Your iterator 
 will be initialized with the root node of a BST.

 Calling next() will return the next smallest number in the BST.

 Note: next() and hasNext() should run in average O(1) time and uses O(h) 
 memory, where h is the height of the tree.

**********************************************************************/

/*
 * Remember how you can travesal without using recursive,
 * record which nodes have not been visited.
 */
class BSTIterator {
public:
    void pushNode(TreeNode *node) {
        TreeNode *cur = node;
        
        while (NULL != cur) {
            nonvisited.push(cur);
            cur = cur->left;
        }
    }

    BSTIterator(TreeNode *root) {
        pushNode(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nonvisited.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur = nonvisited.top();
        nonvisited.pop();
        
        if (NULL != cur->right)
            pushNode(cur->right);
        return cur->val;
    }
    
private:
    stack<TreeNode *> nonvisited;
};

