/**********************************************************************

 Given a binary tree and a sum, find all root-to-leaf paths where each 
 path's sum equals the given sum.

 For example:
 Given the below binary tree and sum = 22,
               5
              / \
             4   8
            /   / \
           11  13  4
          /  \    / \
         7    2  5   1
 return
 [
    [5,4,11,2],
    [5,8,4,5]
 ]

**********************************************************************/

class Solution {
public:

    void dfs(TreeNode *node, int sum) {
        if (NULL == node)
            return ;
            
        path.push_back(node->val);
        pathsum += node->val;
        if (NULL == node->left && NULL == node->right && pathsum == sum) {
            paths.push_back(path);
            goto ret;
        }
        
        dfs(node->left, sum);
        dfs(node->right, sum);

ret:        
        path.pop_back();
        pathsum -= node->val;
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        pathsum = 0;
        dfs(root, sum);
        return paths;
    }

private:
    std::vector<std::vector<int>> paths;
    std::vector<int> path;
    int pathsum;
};
