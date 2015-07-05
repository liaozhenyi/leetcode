/**********************************************************************

 There are two sorted arrays A and B of size m and n respectively. Find 
 the median of the two sorted arrays. The overall run time complexity 
 should be O(log (m+n)).

**********************************************************************/

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

/* 2nd round @07.05 */

static inline int getMin(int a, int b) {
	return a > b ? b : a;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
	int low1, high1, low2, high2, mid1, mid2;

	low1 = 0;
	high1 = nums1.size()-1;
	low2 = 0;
	high2 = nums2.size()-1;

	double median1, median2;
	while (low1 < high1-1 && low2 < high2-1) {
		mid1 = (low1+high1)/2;
		mid2 = (low2+high2)/2;
		median1 = (high1-low1)%2 ? ((double)nums1[mid1]+nums1[mid1+1])/2 : num1[mid1];
		median2 = (high2-low2)%2 ? ((double)nums2[mid2]+nums2[mid2+1])/2 : num2[mid2];
		// when the arr size is even, you can't cut a real half!
		int halfsize1 = (high1-low1)/2;
		int halfsize2 = (high2-low2)/2;
		int delSize = getMin(halfsize1, halfsize2);

		if (median1 == median2) {
			return median1;
		} else if (median1 > median2) {
			high1 -= delSize;
			low2 += delSize;
		} else {
			high2 -= delSize;
			low1 += delSize;
		}
	}
	
	vector<int> arr;
	while (low1 <= high1 && low2 <= high2) {
		if (nums1[low1] < nums[low2])
			arr.push_back(nums1[low1++]);
		else
			arr.push_back(nums2[low2++]);
	}
	while (low1 <= high1)
		arr.push_back(nums1[low1++]);
	while (low2 <= high2)
		arr.push_back(nums2[low2++]);


	if (arr.size()%2)
		return (double)arr[arr.size()/2];
	else
		return ((double)arr[arr.size()/2] + arr[arr.size()/2+1])/2;
}
