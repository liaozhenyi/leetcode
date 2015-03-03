/**********************************************************************

 Follow up for "Unique Paths":
 
 Now consider if some obstacles are added to the grids. How many unique 
 paths would there be?
 
 An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 
 For example,
 There is one obstacle in the middle of a 3x3 grid as illustrated below.
 
 [
   [0,0,0],
   [0,1,0],
   [0,0,0]
 ]
 The total number of unique paths is 2.
 
 Note: m and n will be at most 100.

**********************************************************************/

#include <iostream>
#include <vector>
using namespace std;

const int ARRAYSIZE = 100;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	int paths[ARRAYSIZE] = {0};

	if (!obstacleGrid.size() || !obstacleGrid[0].size())
		return 0;
	
	paths[0] = (obstacleGrid[0][0] == 0 ? 1 : 0);
	for (int j = 1; j < obstacleGrid[0].size(); j++)
		paths[j] = paths[j-1] & !obstacleGrid[0][j];

	for (int i = 1; i < obstacleGrid.size(); i++) {
		for (int j = 0; j < obstacleGrid[0].size(); j++) {
			if (obstacleGrid[i][j])
				paths[j] = 0;
			else if (j)
				paths[j] += paths[j-1];
		}
	}
	
	return paths[obstacleGrid[0].size()-1];
}

int main(int argc, char *argv[]) {
	int array1[] = {0,0,0,0,1,0,0,0,0};
	int array2[] = {0,1,0,1,0,0,0,0,0};
	int array3[] = {0,0,0,0,0,0,0,0,0};
	vector<vector<int> > obstacleGrid1, obstacleGrid2, obstacleGrid3;

	obstacleGrid1.push_back(vector<int>(array1, array1+3));
	obstacleGrid1.push_back(vector<int>(array1+3, array1+6));
	obstacleGrid1.push_back(vector<int>(array1+6, array1+9));

	obstacleGrid2.push_back(vector<int>(array2, array2+3));
	obstacleGrid2.push_back(vector<int>(array2+3, array2+6));
	obstacleGrid2.push_back(vector<int>(array2+6, array2+9));

	obstacleGrid3.push_back(vector<int>(array3, array3+3));
	obstacleGrid3.push_back(vector<int>(array3+3, array3+6));
	obstacleGrid3.push_back(vector<int>(array3+6, array3+9));

	cout << uniquePathsWithObstacles(obstacleGrid1) << endl;
	cout << uniquePathsWithObstacles(obstacleGrid2) << endl;
	cout << uniquePathsWithObstacles(obstacleGrid3) << endl;

	return 0;
}
