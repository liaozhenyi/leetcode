/**********************************************************************

 There are two sorted arrays A and B of size m and n respectively. Find 
 the median of the two sorted arrays. The overall run time complexity 
 should be O(log (m+n)).

**********************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(int A[], int m, int B[], int n) {
	int midIndexA, midIndexB, cut;
	vector<double> arr;
	int arrSize, arrMid;

	midIndexA = (m-1)/2;
	midIndexB = (n-1)/2;

	if (!m && !n)
		return 0;
	if (m < 0 || n < 0)
		return 0;
	if (!n)
		return m%2 ? A[midIndexA] : ((double)(A[midIndexA]+A[midIndexA+1]))/2;
	if (!m)
		return n%2 ? B[midIndexB] : ((double)(B[midIndexB]+B[midIndexB+1]))/2;
	if (m < n)
		return findMedianSortedArrays(B, n, A, m);

	// when n < 3, cut equals to 0 in each round,
	// it's time to get the works done
	// get all the candidates, and calculate the median
	if (n < 3) {
		arr.push_back(B[0]);
		if (n == 2)
			arr.push_back(B[1]);

		arr.push_back(A[midIndexA]);
		if (m%2 && m > 2) {
			arr.push_back(A[midIndexA-1]);
			arr.push_back(A[midIndexA+1]);
		} else if (!(m%2) && m < 3) {
			arr.push_back(A[midIndexA+1]);
		} else if (!(m%2) && m > 2) {
			arr.push_back(A[midIndexA-1]);
			arr.push_back(A[midIndexA+1]);
			arr.push_back(A[midIndexA+2]);
		}

		sort(arr.begin(), arr.end());
		arrSize = arr.size();
		arrMid = (arrSize-1)/2;
		return arrSize%2 ? arr[arrMid] : (arr[arrMid]+arr[arrMid+1])/2;
	}

	cut = midIndexB;
	// when A[midIndexA] = B[midIndexB], the median may
	// not be the same value, think about it!
	if (A[midIndexA] > B[midIndexB])
		return findMedianSortedArrays(A, m-cut, &B[cut], n-cut);
	else
		return findMedianSortedArrays(&A[cut], m-cut, B, n-cut);
}

int main(int argc, char *argv[])
{
	int arr1[1] = {1};
	int arr2[2] = {3, 5};
	int arr3[3] = {2, 3, 4};
	int arr4[4] = {5, 6, 7, 8};
	int arr5[4] = {6, 7, 8, 9};
	int arr6[4] = {1, 5, 6, 7};
	int arr7[6] = {2, 3, 4, 8, 9, 10};

	cout << findMedianSortedArrays(arr1, 1, arr2, 2) << endl;
	cout << findMedianSortedArrays(arr2, 2, arr3, 3) << endl;
	cout << findMedianSortedArrays(arr3, 3, arr4, 4) << endl;
	cout << findMedianSortedArrays(arr4, 4, arr5, 4) << endl;
	cout << findMedianSortedArrays(arr5, 4, arr6, 4) << endl;
	cout << findMedianSortedArrays(arr6, 4, arr7, 6) << endl;

	return 0;
}
