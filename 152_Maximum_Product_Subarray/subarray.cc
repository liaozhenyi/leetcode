/**********************************************************************

 Find the contiguous subarray within an array (containing at least one 
 number) which has the largest product.

 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.

**********************************************************************/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int maxProduct(int A[], int n) {
	int temp, ans;
	vector<vector<int> > product;

	if (!n)
		return 0;

	for (int i = 0; i < n; i++) {
		product.push_back(vector<int>());
		if (!i || !A[i]) {
			product[i].push_back(A[i]);
		} else {
			product[i].push_back(A[i]);
			for (int j = 0; j < product[i-1].size(); j++) {
				if (!product[i-1][j]) {
					product[i].push_back(A[i]);
					continue;
				}
				temp = product[i-1][j]*A[i];
				product[i].push_back(temp);
			}
			if (product[i].size() > 2) {
				sort(product[i].begin(), product[i].end());
				product[i].erase(product[i].begin()+1, product[i].end()-1);
			}
		}
	}

	ans = INT_MIN;
	for (int i = 0; i < product.size(); i++)
		for (int j = 0; j < product[i].size(); j++)
			if (ans < product[i][j])
				ans = product[i][j];
	return ans;
}

int main(int argc, char *argv[])
{
	int array1[] = {-3,2,4,7,-5,1,6,-2,1,7,0};
	int array2[] = {-1};
	int array3[] = {2,-5,-2,-4,3};
	int array4[] = {-3,2,4,7,-5,0,1,6,-2,1,7};
	int array5[] = {1,6,-2,1,7,0,0,-3,2,4,7,-5};

	cout << maxProduct(array1, sizeof(array1)/sizeof(int)) << endl;
	cout << maxProduct(array2, sizeof(array2)/sizeof(int)) << endl;
	cout << maxProduct(array3, sizeof(array3)/sizeof(int)) << endl;
	cout << maxProduct(array4, sizeof(array4)/sizeof(int)) << endl;
	cout << maxProduct(array5, sizeof(array5)/sizeof(int)) << endl;

	return 0;
}
