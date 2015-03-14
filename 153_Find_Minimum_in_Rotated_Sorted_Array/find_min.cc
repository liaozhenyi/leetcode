/**********************************************************************

 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 Find the minimum element.
 
 You may assume no duplicate exists in the array.

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/* first find the pivot */
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
		} else {
			high = mid;
		}
	}

	return num[low];
}

int main(int argc, char *argv[])
{
	int arr1[] = {4,5,6,7,0,1};
	int arr2[] = {1,2,3,4,5};
	vector<int> num1, num2;

	num1 = vector<int>(arr1, arr1+sizeof(arr1)/sizeof(int));
	num2 = vector<int>(arr2, arr2+sizeof(arr2)/sizeof(int));

	cout << findMin(num1) << endl;
	cout << findMin(num2) << endl;

	return 0;
}
