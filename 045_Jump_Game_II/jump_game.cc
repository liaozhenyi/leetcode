/**********************************************************************

 Given an array of non-negative integers, you are initially positioned at 
 the first index of the array.

 Each element in the array represents your maximum jump length at that position.
 
 Your goal is to reach the last index in the minimum number of jumps.
 
 For example:
 Given array A = [2,3,1,1,4]
 
 The minimum number of jumps to reach the last index is 2. (Jump 1 step 
 from index 0 to 1, then 3 steps to the last index.)

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * o(n^2) solution, get a "Time Limit Exceed" ERROR!
 * time complexity is O(sum of array elements)
inline int getMin(int a, int b) {
	return (a > b ? b : a);
}

int jump(int A[], int n) {
	int ans;
	int *minJump = new int[n];

	for (int i = n-1; i >= 0; i--) {
		if (i == n-1) {
			minJump[i] = 0;
			continue;
		}
		minJump[i] = INT_MAX;
		if(A[i] > 0) {
			for (int j = i+1; j <= getMin(n-1, i+A[i]); j++) {
				if (minJump[j] == INT_MAX)
					continue;
				if (minJump[j]+1 < minJump[i])
					minJump[i] = minJump[j]+1;
			}
		}
	}

	ans = minJump[0];
	delete []minJump;
	return ans;
}
*/

/*
 * Get "Time Limit Exceed" ERROR again!
 * When A[] is consist of 1, the time complexity is O(n^2)
int jump(int A[], int n) {
	int ans;
	// jumpNumIdx[i] store the smallest idx that 
	// can move to the end position in i jumps.
	vector<int> jumpNumIdx;
	vector<int>::iterator it;

	ans = INT_MAX;
	if (n <= 0)
		return ans;

	for (int i = n-1; i >= 0; i--) {
		if (i == n-1) {
			jumpNumIdx.push_back(n-1);
			continue;
		}
		for (it = jumpNumIdx.begin(); it != jumpNumIdx.end(); it++) {
			if (i+A[i] < *it)
				continue;
			if (it+1 == jumpNumIdx.end())
				jumpNumIdx.push_back(i);
			else
				*(it+1) = i;
			break;
					
		}
	}

	for (it = jumpNumIdx.begin(); it != jumpNumIdx.end(); it++) {
		if (*it == 0) {
			ans = it-jumpNumIdx.begin();
			break;
		}
	}
	return ans;
}
*/

int jump(int A[], int n) {
	int jumpCount;
	int prePosition, curPosition;

	jumpCount = 0;
	prePosition = 0;
	curPosition = 0;
	while (curPosition < n-1) {
		int farPosition = curPosition;
		for (int i = prePosition; i <= curPosition; i++) {
			if (i+A[i] > farPosition)
				farPosition = i+A[i];
		}
		if (farPosition == curPosition)
			return INT_MAX;
		prePosition = curPosition;
		curPosition = farPosition;
		jumpCount++;
	}

	return jumpCount;
}

int main(int argc, char *argv[]) {
	int array1[] = {2,3,1,1,4};
	int array2[] = {3,2,1,0,4};
	int array3[] = {4,0,0,0,3,0,0};
	int array4[] = {0,1,1,2,3,4};
	int array5[25000];
	int array6[25000];

	for (int i = 0; i < 25000; i++) {
		array5[i] = 25000-i;
		array6[i] = 1;
	}

	cout << jump(array1, sizeof(array1)/sizeof(int)) << endl;
	cout << jump(array2, sizeof(array2)/sizeof(int)) << endl;
	cout << jump(array3, sizeof(array3)/sizeof(int)) << endl;
	cout << jump(array4, sizeof(array4)/sizeof(int)) << endl;
	cout << jump(array5, sizeof(array5)/sizeof(int)) << endl;
	cout << jump(array6, sizeof(array6)/sizeof(int)) << endl;

	return 0;
}
