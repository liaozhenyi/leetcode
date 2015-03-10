/**********************************************************************

 Given a sorted array and a target value, return the index if the target 
 is found. If not, return the index where it would be if it were inserted 
 in order.

 You may assume no duplicates in the array.
 
 Here are few examples.
 [1,3,5,6], 5 → 2
 [1,3,5,6], 2 → 1
 [1,3,5,6], 7 → 4
 [1,3,5,6], 0 → 0

**********************************************************************/

#include <iostream>

using namespace std;

int searchInsert(int A[], int n, int target) {
	int low, high, mid;

	low = 0;
	high = n-1;

	while (low <= high) {
	// another solution:
	// while(low < high) {
		mid = (low+high)/2;
		if (A[mid] == target) {
			return mid;
		} else if (A[mid] > target) {
			high = mid-1;
		} else {
			low = mid+1;
		}
	}

	// if not found in array
	return low;

	// another solution
	// if (A[low] >= target)
	// 	return low;
	// else
	// 	return low+1;
}

int main(int argc, char *argv[]) {
	int array1[] = {0};
	int array2[] = {0,1,5,10};
	int array3[] = {};
	int array4[] = {300};

	cout << searchInsert(array1, sizeof(array1)/sizeof(int), 2) << endl;
	cout << searchInsert(array2, sizeof(array2)/sizeof(int), 2) << endl;
	cout << searchInsert(array3, sizeof(array3)/sizeof(int), 2) << endl;
	cout << searchInsert(array4, sizeof(array4)/sizeof(int), 2) << endl;

	return 0;
}
