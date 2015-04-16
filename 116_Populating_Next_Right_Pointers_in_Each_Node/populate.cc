/**********************************************************************

 Given a binary tree
 
     struct TreeLinkNode {
       TreeLinkNode *left;
       TreeLinkNode *right;
       TreeLinkNode *next;
     }
 Populate each next pointer to point to its next right node. If there is 
 no next right node, the next pointer should be set to NULL.
 
 Initially, all next pointers are set to NULL.
 
 Note:
 
 You may only use constant extra space.
 You may assume that it is a perfect binary tree (ie, all leaves are at the 
 same level, and every parent has two children).
 For example,
 Given the following perfect binary tree,
          1
        /  \
       2    3
      / \  / \
     4  5  6  7
 After calling your function, the tree should look like:
          1 -> NULL
        /  \
       2 -> 3 -> NULL
      / \  / \
     4->5->6->7 -> NULL

**********************************************************************/

void connect(TreeLinkNode *root)
{
	std::queue<TreeLinkNode *> nodeQueue;
	TreeLinkNode *tail, *cur, *pre;

	if (NULL == root)
		return ;

	nodeQueue.push(root);
	while (!nodeQueue.empty()) {
		pre = NULL;
		tail = nodeQueue.back();

		do {
			cur = nodeQueue.front();
			nodeQueue.pop();
			if (cur->left)
				nodeQueue.push(cur->left);
			if (cur->right)
				nodeQueue.push(cur->right);
			if (pre)
				pre->next = cur;
			pre = cur;
		} while (cur != tail);
		cur->next = NULL;
	}
}
