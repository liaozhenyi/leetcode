/**********************************************************************

 Given a sorted array of integers, find the starting and ending position 
 of a given target value.

 Your algorithm's runtime complexity must be in the order of O(log n).
 
 If the target is not found in the array, return [-1, -1].
 
 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(int A[], int n, int target) {
	int low, high, mid;
	int lowIdx, highIdx;
	vector<int> range;

	low = 0;
	high = n-1;
	lowIdx = -1;
	highIdx = -1;

	while (low <= high) {
		mid = (low+high)/2;	
		if (A[mid] > target) {
			high = mid-1;
		} else if (A[mid] < target) {
			low = mid+1;
		} else {
			int low1, high1, mid1;
			low1 = low;
			high1 = mid;
			while (low1 < high1) {
				mid1 = (low1+high1)/2;
				if (A[mid1] < target)
					low1 = mid1+1;
				else
					high1 = mid1-1;
			}
			lowIdx = (A[low1] == target ? low1 : low1+1);

			low1 = mid;
			high1 = high;
			while (low1 < high1) {
				mid1 = (low1+high1)/2;
				if (A[mid1] > target)
					high1 = mid1-1;
				else
					low1 = mid1+1;
			}
			highIdx = (A[low1] == target ? low1 : low1-1);

			break;
		}
	}

	range.push_back(lowIdx);
	range.push_back(highIdx);
	return range;
}

int main(int argc, char *argv[])
{
	int arr1[] = {};
	int arr2[] = {1,3,5,7,9,11};
	int arr3[] = {1,5,5,5,9,9};
	int arr4[] = {1,5,9,11,13,15};
	int arr5[] = {5};
	int arr6[] = {3,5,7};
	vector<int> range;
	
	range = searchRange(arr1, sizeof(arr1)/sizeof(int), 5);
	for (vector<int>::iterator it = range.begin(); it != range.end(); it++)
		cout << *it << " ";
	cout << endl;

	range = searchRange(arr2, sizeof(arr2)/sizeof(int), 5);
	for (vector<int>::iterator it = range.begin(); it != range.end(); it++)
		cout << *it << " ";
	cout << endl;

	range = searchRange(arr3, sizeof(arr3)/sizeof(int), 5);
	for (vector<int>::iterator it = range.begin(); it != range.end(); it++)
		cout << *it << " ";
	cout << endl;

	range = searchRange(arr4, sizeof(arr4)/sizeof(int), 5);
	for (vector<int>::iterator it = range.begin(); it != range.end(); it++)
		cout << *it << " ";
	cout << endl;

	range = searchRange(arr5, sizeof(arr5)/sizeof(int), 5);
	for (vector<int>::iterator it = range.begin(); it != range.end(); it++)
		cout << *it << " ";
	cout << endl;

	range = searchRange(arr6, sizeof(arr6)/sizeof(int), 5);
	for (vector<int>::iterator it = range.begin(); it != range.end(); it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}
