/**********************************************************************

 Follow up for "Find Minimum in Rotated Sorted Array":
 What if duplicates are allowed?
 
 Would this affect the run-time complexity? How and why?
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 Find the minimum element.
 
 The array may contain duplicates.

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/* If duplicates are allowed, the time complexity
 * in the worst case will be O(n). Consider a array
 * contains the same number in all position but one.
 * In such conditions, num[low] = num[mid] = num[high],
 * you cann't discard any part of the array.
 */
int findMin(vector<int> &num) {
	int low, high, mid;

	if (!num.size())
		return -1;
	
	low = 0;
	high = num.size()-1;
	while (low < high) {
		mid = (low+high)/2;
		if (num[mid] > num[high]) {
			low = mid+1;
		} else if (num[mid] < num[high]) {
			high = mid;
		} else {
			if (num[mid] < num[num.size()-1]) {
				high = mid;
			} else {
				//otherwise, num[mid] = num[num.size()-1]
				if (num[mid] < num[0]) {
					high = mid;
				} else {
					--high;
				}
			}
		}
	}
	
	return num[low];
}

int main(int argc, char *argv[])
{
	int arr[1000] = {0};
	vector<int> num;

	for (int i = 0; i < 1000; i++) {
		arr[i] = -2;
		num = vector<int>(arr, arr+sizeof(arr)/sizeof(int));
		cout << findMin(num) << " ";
		arr[i] = 0;
	}
	return 0;
}
