/**********************************************************************

 Find the contiguous subarray within an array (containing at least one 
 number) which has the largest sum.

 For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 the contiguous subarray [4,−1,2,1] has the largest sum = 6.

**********************************************************************/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/**
 * Method One: Dynamic Programming
 */
int maxSubArray(int A[], int n) {
	int *sum = new int[n];
	int max = -INT_MAX;

	if (!n)
		return 0;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			sum[i] = A[i];
		else
			sum[i] = sum[i-1]>0 ? sum[i-1]+A[i] : A[i];
		if (sum[i] > max)
			max = sum[i];
	}
	delete []sum;

	return max;
}

/**
 * Method Two: Divide and Conque
 */
int maxSubArray(int A[], int n) {
	int maxLeftHalf, maxRightHalf, maxMiddle;
	int mid, countLeft, countRight, sum;

	if (!n)
		return 0;
	if (n == 1)
		return A[0];

	mid = (n-1)/2;

	countLeft = -INT_MAX;
	sum = 0;
	for (int i = mid; i>=0; i--) {
		sum += A[i];
		if (countLeft < sum)
			countLeft = sum;
	}

	countRight = -INT_MAX;
	sum = 0;
	for (int i = mid+1; i < n; i++) {
		sum += A[i];
		if (countRight < sum)
			countRight = sum;
	}

	maxMiddle = countLeft + countRight;
	maxLeftHalf = maxSubArray(A, mid+1);
	maxRightHalf = maxSubArray(&A[mid+1], n-mid-1);

	if (maxLeftHalf > maxRightHalf)
		return maxLeftHalf > maxMiddle ? maxLeftHalf : maxMiddle;
	else
		return maxRightHalf > maxMiddle ? maxRightHalf : maxMiddle;
}

int main(int argc, char *argv[])
{
	int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int B[] = {1, 2, 3};
	int C[] = {-1, -2, -3};
	int max;

	max = maxSubArray(A, sizeof(A)/sizeof(int));
	cout << max << endl;
	max = maxSubArray(B, sizeof(B)/sizeof(int));
	cout << max << endl;
	max = maxSubArray(C, sizeof(C)/sizeof(int));
	cout << max << endl;
		
	return 0;
}
