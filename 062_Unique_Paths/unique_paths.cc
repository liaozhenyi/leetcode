/**********************************************************************

 A robot is located at the top-left corner of a m x n grid (marked 'Start'
 in the diagram below).

 The robot can only move either down or right at any point in time. The 
 robot is trying to reach the bottom-right corner of the grid (marked 
 'Finish' in the diagram below).

 How many possible unique paths are there?

**********************************************************************/

#include <iostream>
using namespace std;

const int ARRAYSIZE = 200;

/*
 * Method One
 */
/*
int uniquePaths(int m, int n) {
	int min, sum;
	double ans;

	if (m < 1 || n < 1)
		return 0;

	min = m>n ? n-1 : m-1;
	sum = m+n-2;
	ans = 1;

	for (int i = sum; i > sum-min; i--)
		ans *= i; // may overflow
	for (int i = 1; i <= min; i++)
		ans /= i;

	return ans;
}
*/

/*
 * Method Two
 */
int uniquePaths(int m, int n) {
	int min, sum, ans;
	int combination[ARRAYSIZE] = {0};
	
	if (m < 1 || n < 1)
		return 0;
	
	min = m>n ? n-1 : m-1;
	sum = m+n-2;

	combination[0] = 1;

	for (int i = 1; i <= sum; i++) {
		for (int j = i; j > 0; j--) {
			combination[j] += combination[j-1];
		}
	}
	ans = combination[min];

	return ans;
}

int main(int argc, char *argv[]) {
	cout << uniquePaths(3, 7) << endl;
	cout << uniquePaths(99, 1) << endl;
	cout << uniquePaths(1, 10) << endl;
	
	return 0;
}
