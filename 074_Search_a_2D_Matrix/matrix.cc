/**********************************************************************

 Write an efficient algorithm that searches for a value in an m x n matrix. 
 This matrix has the following properties:

 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 For example,
 
 Consider the following matrix:
 
 [
   [1,   3,  5,  7],
   [10, 11, 16, 20],
   [23, 30, 34, 50]
 ]
 Given target = 3, return true.

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {
	int low, high, mid;
	int rowNo;

	if (!matrix.size() || !matrix[0].size())
		return false;

	low = 0;
	high = matrix.size()-1;
	while (low < high) {
		mid = (low+high)/2;
		int value = matrix[mid].back();
		if (value > target) {
			high = mid;
		} else if (value < target) {
			low = mid+1;
		} else {
			return true;
		}
	}
	rowNo = low;

	if (rowNo == matrix.size())
		return false;

	low = 0;
	high = matrix[rowNo].size()-1;
	while (low < high) {
		mid = (low+high)/2;
		if (matrix[rowNo][mid] == target) {
			return true;
		} else if (matrix[rowNo][mid] > target) {
			high = mid-1;
		} else {
			low = mid+1;
		}
	}

	return low < matrix[rowNo].size() && matrix[rowNo][low] == target;
}

int main(int argc, char *argv[]) {
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	vector<vector<int> > matrix;

	cout << searchMatrix(matrix, 7) << endl;
	
	matrix.push_back(vector<int>(arr, arr+5));
	cout << searchMatrix(matrix, 7) << endl;

	matrix.push_back(vector<int>(arr+5, arr+10));
	cout << searchMatrix(matrix, 7) << endl;

	matrix.push_back(vector<int>(arr+10, arr+15));
	cout << searchMatrix(matrix, 7) << endl;
	return 0;
}
