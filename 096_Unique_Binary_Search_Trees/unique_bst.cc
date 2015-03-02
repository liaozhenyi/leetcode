/**********************************************************************

 Given n, how many structurally unique BST's (binary search trees) that 
 store values 1...n?

**********************************************************************/

#include <iostream>

const int ARRAYSIZE = 500;

int numTrees(int n) {
	int count[ARRAYSIZE] = {0};

	count[0] = 1;
	count[1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++)
			count[i] += count[j]*count[i-j-1];
	}
	return count[n];
}

int main(int argc, char *argv[])
{
	for (int i = 0; i < 10; i++)
		std::cout << numTrees(i) << std::endl;

	return 0;
}
