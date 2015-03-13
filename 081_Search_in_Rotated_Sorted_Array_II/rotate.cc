/**********************************************************************

 Follow up for "Search in Rotated Sorted Array":
 What if duplicates are allowed?
 
 Would this affect the run-time complexity? How and why?
 
 Write a function to determine if a given target is in the array.

**********************************************************************/

#include <iostream>

bool searchInArray(int A[], int n, int target) {
	int low, high, mid;
	
	if (!n)
		return false;

	low = 0;
	high = n-1;
	while (low < high) {
		mid = (low+high)/2;
		if (A[mid] == target) {
			return true;
		} else if (A[mid] > target) {
			high = mid-1;
		} else {
			low = mid+1;
		}
	}

	return A[low] == target;
}

bool search(int A[], int n, int target) 
{
	int pivot;
	int high, low, mid;

	if (!n)
		return false;
	if (n == 1)
		return A[0] == target;

	pivot = -1;
	high = n-1;
	low = 0;
	while (low < high) {
		mid = (low+high)/2;
		if (A[mid] > A[n-1]) {
			low = mid+1;
		} else if (A[mid] < A[n-1]) {
			high = mid;
		} else {
			if (A[0] == A[n-1]) {
				// pivot contains in [low, high]
				pivot = high;
				while (pivot > low && A[pivot] >= A[pivot-1])
					pivot--;
				break;
			} else {
				high = mid;
			}
		}
	}
	if (pivot == -1) {
		pivot = low;
	}
	//std::cout << pivot << " - ";

	if (searchInArray(A, pivot, target))
		return true;
	return searchInArray(&A[pivot], n-pivot, target);
}

int main(int argc, char *argv[])
{
	int arr1[] = {};
	int arr2[] = {4,5,6,7,0,1,2};
	int arr3[] = {0,2,4,6,8,10,12};
	int arr4[] = {7,7,7,7,7,2,7};
	int arr5[] = {2};
	int arr6[] = {3,1};
	int arr7[] = {5,1,3};
	int arr8[] = {1,1,2,0,0,1};

	std::cout << search(arr1, 0, 7) << std::endl;
	std::cout << search(arr2, sizeof(arr2)/sizeof(int), 3) << std::endl;
	std::cout << search(arr3, sizeof(arr3)/sizeof(int), 8) << std::endl;
	std::cout << search(arr4, sizeof(arr4)/sizeof(int), 2) << std::endl;
	std::cout << search(arr5, sizeof(arr5)/sizeof(int), 2) << std::endl;
	std::cout << search(arr6, sizeof(arr6)/sizeof(int), 1) << std::endl;
	std::cout << search(arr7, sizeof(arr7)/sizeof(int), 2) << std::endl;
	std::cout << search(arr8, sizeof(arr8)/sizeof(int), 0) << std::endl;

	return 0;
}
