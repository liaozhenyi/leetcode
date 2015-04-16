/**********************************************************************

 Given a binary tree, flatten it to a linked list in-place.

 For example,
 Given
 
          1
         / \
        2   5
       / \   \
      3   4   6
 The flattened tree should look like:
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
 
**********************************************************************/

void flatten(TreeNode *root) {
	TreeNode *head = NULL, *tail = NULL, *cur;
	std::stack<TreeNode *> nodeStack;

	if (NULL == root)
		return ;

	nodeStack.push(root);
	while (!nodeStack.empty()) {
		cur = nodeStack.top();
		nodeStack.pop();
		if (cur->right)
			nodeStack.push(cur->right);
		if (cur->left)
			nodeStack.push(cur->left);

		if (NULL == head) {
			head = cur;
			tail = cur;
		} else {
			tail->right = cur;
			tail = cur;
		}
		cur->left = NULL;
	}
	tail->right = NULL;
}
