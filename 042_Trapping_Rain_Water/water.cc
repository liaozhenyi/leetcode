/********************************************************************** 

 Given n non-negative integers representing an elevation map where the 
 width of each bar is 1, compute how much water it is able to trap after raining.

 For example, 
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

**********************************************************************/

#include <iostream>

using namespace std;

static inline int getMin(int a, int b) {
	return (a>b ? b : a);
}

int trap(int A[], int n) {
	int ans;
	int *maxFromLeft, *maxFromRight;

	ans = 0;
	maxFromLeft = new int[n];
	maxFromRight = new int[n];

	if (!maxFromLeft || !maxFromRight)
		goto end;

	maxFromLeft[0] = A[0];
	for (int i = 1; i < n; i++) {
		maxFromLeft[i] = A[i]>maxFromLeft[i-1] ? A[i] : maxFromLeft[i-1];
	}
	maxFromRight[n-1] = A[n-1];
	for (int i = n-2; i >= 0; i--) {
		maxFromRight[i] = A[i]>maxFromRight[i+1] ? A[i] : maxFromRight[i+1];
	}
	for (int i = 0; i < n; i++) {
		ans += getMin(maxFromLeft[i], maxFromRight[i])-A[i];
	}

end:
	if (maxFromLeft)
		delete []maxFromLeft;
	if (maxFromRight)
		delete []maxFromRight;

	return ans;
}

int main(int argc, char *argv[])
{
	int arr1[] = {0,1,0,2,1,0,1,3,2,1,2,1};

	std::cout << trap(arr1, 0) << std::endl;
	std::cout << trap(arr1, 3) << std::endl;
	std::cout << trap(arr1, 5) << std::endl;
	std::cout << trap(arr1, sizeof(arr1)/sizeof(int)) << std::endl;

	return 0;
}
