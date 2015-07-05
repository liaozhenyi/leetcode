/**********************************************************************

 Given a binary tree, return the bottom-up level order traversal of its 
 nodes' values. (ie, from left to right, level by level from leaf to root).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
     3
    / \
   9  20
     /  \
    15   7
 return its bottom-up level order traversal as:
 [
   [15,7],
   [9,20],
   [3]
 ]

**********************************************************************/

class Solution {
public:

    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> tmp, ans;
        
        if (NULL == root)
            return ans;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            vector<int> level;
            TreeNode *last = nodeQueue.back(), *cur;
            
            do {
                cur = nodeQueue.front();
                nodeQueue.pop();
                
                level.push_back(cur->val);
                
                if (cur->left)
                    nodeQueue.push(cur->left);
                if (cur->right)
                    nodeQueue.push(cur->right);
            } while (cur != last);
            tmp.push_back(level);
        }
        
        for (auto l = tmp.rbegin(); l != tmp.rend(); ++l)
            ans.push_back(*l);
            
        return ans;
    }
    
private:
    std::queue<TreeNode *> nodeQueue;
    
};
