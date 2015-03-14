/**********************************************************************

 A peak element is an element that is greater than its neighbors.

 Given an input array where num[i] ≠ num[i+1], find a peak element and return 
 its index.
 
 The array may contain multiple peaks, in that case return the index to any 
 one of the peaks is fine.
 
 You may imagine that num[-1] = num[n] = -∞.
 
 For example, in array [1, 2, 3, 1], 3 is a peak element and your function 
 should return the index number 2.

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(const vector<int> &num) {
	int low, high, mid;

	if (!num.size())
		return -1;

	low = 0;
	high = num.size()-1;
	while (low < high) {
		mid = (low+high)/2;
		if (num[mid] < num[high]) {
			low = mid+1;
		} else if (num[mid] < num[low]) {
			high = mid-1;
		} else {
			if (!mid) {
				if (num[mid] > num[mid+1])
					return mid;
				else
					low = mid+1;
			} else {
				if (num[mid] > num[mid+1] && \
					num[mid] > num[mid-1])
					return mid;
				else if (num[mid] > num[mid+1] && \
					num[mid] < num[mid-1])
					high = mid-1;
				else if (num[mid] < num[mid+1] && \
					num[mid] > num[mid-1])
					low = mid+1;
				else
					low = mid+1;
			}
		}
	}
	return low;
}

int main(int argc, char *argv[])
{
	int arr1[] = {1};
	int arr2[] = {5,2};
	int arr3[] = {1,2,3,4,5,1};
	int arr4[] = {1,5,4,3,2,1};
	vector<int> num1, num2, num3, num4;

	num1 = vector<int>(arr1, arr1+sizeof(arr1)/sizeof(int));
	num2 = vector<int>(arr2, arr2+sizeof(arr2)/sizeof(int));
	num3 = vector<int>(arr3, arr3+sizeof(arr3)/sizeof(int));
	num4 = vector<int>(arr4, arr4+sizeof(arr4)/sizeof(int));

	cout << findPeakElement(num1) << endl;
	cout << findPeakElement(num2) << endl;
	cout << findPeakElement(num3) << endl;
	cout << findPeakElement(num4) << endl;

	return 0;
}
