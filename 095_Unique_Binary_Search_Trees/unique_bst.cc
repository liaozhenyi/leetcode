/**********************************************************************

 Given n, generate all structurally unique BST's (binary search trees) 
 that store values 1...n.

 For example,
 Given n = 3, your program should return all 5 unique BST's shown below.
 
    1         3     3      2      1
     \       /     /      / \      \
      3     2     1      1   3      2
     /     /       \                 \
    2     1         2                 3

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

struct TreeNode * copyTree(struct TreeNode *src, int addValue)
{
	if (!src)
		return NULL;

	struct TreeNode *newTree = new TreeNode(src->val+addValue);
	newTree->left = copyTree(src->left, addValue);
	newTree->right = copyTree(src->right, addValue);

	return newTree;
}

vector<TreeNode *> generateTrees(int n) {
	vector<vector<TreeNode *> > trees(n+1, vector<TreeNode *>());

	trees[0].push_back(NULL);
	for (int i = 1; i <= n; i++) {
		for (int left = 0; left <= i-1; left++) {
			int right = i-1-left;
			for (int j = 0; j < trees[left].size(); j++)
				for (int k = 0; k < trees[right].size(); k++) {
					struct TreeNode *newTree = new TreeNode(left+1);
					newTree->left = copyTree(trees[left][j], 0);
					newTree->right = copyTree(trees[right][k], left+1);
					trees[i].push_back(newTree);
				}
		}
	}

	return trees[n];
}

void inorderTransverse(struct TreeNode *node) {
	if (!node)
		return ;
	cout << node->val << " ";
	inorderTransverse(node->left);
	inorderTransverse(node->right);
}

int main(int argc, char *argv[]) {
	vector<TreeNode *> ans;
	
	for (int i = 0; i < 5; i++) {
		ans = generateTrees(i);
		for (int j = 0; j < ans.size(); j++) {
			inorderTransverse(ans[j]);
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}
