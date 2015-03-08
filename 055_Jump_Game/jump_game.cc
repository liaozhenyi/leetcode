/**********************************************************************

 Given an array of non-negative integers, you are initially positioned at 
 the first index of the array.

 Each element in the array represents your maximum jump length at that 
 position.
 
 Determine if you are able to reach the last index.
 
 For example:
 A = [2,3,1,1,4], return true.
 
 A = [3,2,1,0,4], return false.

**********************************************************************/

#include <iostream>

using namespace std;

bool canJump(int A[], int n) {
	int minJump;

	if (!n)
		return false;

	for (int i = n-1; i > 0; i--) {
		if (i == n-1) {
			minJump = 0;
		}
		if (A[i] >= minJump) {
			minJump = 1;
		} else {
			minJump++;
		}
	}

	return A[0] >= minJump;
}

int main(int argc, char *argv[]) {
	int array1[] = {2,3,1,1,4};
	int array2[] = {3,2,1,0,4};
	int array3[] = {4,0,0,0,3,0,0};
	int array4[] = {0,1,1,2,3,4};

	cout << canJump(array1, sizeof(array1)/sizeof(int)) << endl;
	cout << canJump(array2, sizeof(array2)/sizeof(int)) << endl;
	cout << canJump(array3, sizeof(array3)/sizeof(int)) << endl;
	cout << canJump(array4, sizeof(array4)/sizeof(int)) << endl;

	return 0;
}
