/**********************************************************************

 Follow up for problem "Populating Next Right Pointers in Each Node".

 What if the given tree could be any binary tree? Would your previous solution still work?
 
 Note:
 
 You may only use constant extra space.
 For example,
 Given the following binary tree,
          1
        /  \
       2    3
      / \    \
     4   5    7
 After calling your function, the tree should look like:
          1 -> NULL
        /  \
       2 -> 3 -> NULL
      / \    \
     4-> 5 -> 7 -> NULL
 
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
