/**********************************************************************

 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 You are given a target value to search. If found in the array return its 
 index, otherwise return -1.
 
 You may assume no duplicate exists in the array.

**********************************************************************/

#include <iostream>

int searchInArray(int A[], int n, int target) {
	int low, high, mid;

	if (!n)
		return -1;

	low = 0;
	high = n-1;
	while (low < high) {
		mid = (low+high)/2;
		if (A[mid] == target) {
			return mid;
		} else if (A[mid] > target) {
			high = mid-1;
		} else {
			low = mid+1;
		}
	}

	if (A[low] == target)
		return low;
	return -1;
}

int search(int A[], int n, int target) {
	int low, high, mid;
	int pivot;

	if (!n)
		return -1;

	low = 0;
	high = n-1;
	while (low < high) {
		mid = (low+high)/2;
		if (A[mid] < A[n-1]) {
			high = mid-1;
		} else {
			low = mid+1;
		}
	}
	if (A[low] <= A[n-1])
		pivot = low;
	else
		pivot = low+1;

	int ans;
	ans = searchInArray(A, pivot, target);
	if (ans != -1)
		return ans;
	ans = searchInArray(&A[pivot], n-pivot, target);
	if (ans == -1)
		return ans;
	return ans+pivot;
}

int main(int argc, char *argv[])
{
	int arr1[] = {};
	int arr2[] = {4,5,6,7,0,1,2};
	int arr3[] = {0,2,4,6,8,10,12};

	std::cout << search(arr1, 0, 7) << std::endl;
	std::cout << search(arr2, sizeof(arr2)/sizeof(int), 3) << std::endl;
	std::cout << search(arr2, sizeof(arr2)/sizeof(int), 2) << std::endl;
	std::cout << search(arr2, sizeof(arr2)/sizeof(int), 7) << std::endl;
	std::cout << search(arr3, sizeof(arr3)/sizeof(int), 8) << std::endl;

	return 0;
}
