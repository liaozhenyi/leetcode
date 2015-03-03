/**********************************************************************

 Given a m x n grid filled with non-negative numbers, find a path from 
 top left to bottom right which minimizes the sum of all numbers along 
 its path.

 Note: You can only move either down or right at any point in time.

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

const int ARRAYSIZE = 200;

inline int getMin(int a, int b)
{
	return (a > b ? b : a);
}

int minPathSum(vector<vector<int> > &grid) {
	int sum[ARRAYSIZE] = {0};

	if (!grid.size() || !grid[0].size())
		return 0;

	for (int i = 0; i < grid.size(); i++)
		for (int j = 0; j < grid[0].size(); j++) {
			if (!i && !j)
				sum[j] = grid[i][j];
			else if (!i)
				sum[j] = sum[j-1] + grid[i][j];
			else if (!j)
				sum[j] += grid[i][j];
			else
				sum[j] = getMin(sum[j-1], sum[j])+grid[i][j];
		}

	return sum[grid[0].size()-1];
}

int main(int argc, char *argv[])
{
	int array1[] = {1,2,3,4,5,6,7,8,9};
	vector<vector<int> > grid1;

	grid1.push_back(vector<int>(array1, array1+3));
	grid1.push_back(vector<int>(array1+3, array1+6));
	grid1.push_back(vector<int>(array1+6, array1+9));

	cout << minPathSum(grid1) << endl;

	return 0;
}
