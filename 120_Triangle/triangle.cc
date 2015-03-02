/**********************************************************************

 Given a triangle, find the minimum path sum from top to bottom. Each 
 step you may move to adjacent numbers on the row below.

 For example, given the following triangle
 
 [
      [2],
     [3,4],
    [6,5,7],
   [4,1,8,3]
 ]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 
 Note:
 Bonus point if you are able to do this using only O(n) extra space, 
 where n is the total number of rows in the triangle.

**********************************************************************/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

inline int getMin(int a, int b){
	return (a > b ? b : a);
}

int minimumTotal(vector<vector<int> > &triangle) {
	int min = INT_MAX;
	vector<int> pathSum;

	if (!triangle.size())
		return 0;

	for (int i = 0; i < triangle.size(); i++) {
		pathSum.push_back(0);
		for (int j = i; j >= 0; j--) {
			// !j or i==j first, haha
			if (!j) {
				pathSum[j] += triangle[i][j];
			} else if (i == j) {
				pathSum[j] = pathSum[j-1]+triangle[i][j];
			} else {
				pathSum[j] = getMin(pathSum[j-1], pathSum[j])\
							+triangle[i][j];
			}
		}
	}
	for (int i = 0; i < pathSum.size(); i++)
		if (pathSum[i] < min)
			min = pathSum[i];

	return min;
}

int main(int argc, char *argv[])
{
	int myints[] = {2,3,4,6,5,7,4,1,8,3};
	vector<vector<int> > triangle;
	vector<vector<int> > empty;

	triangle.push_back(vector<int>(myints, myints+1));
	triangle.push_back(vector<int>(myints+1, myints+3));
	triangle.push_back(vector<int>(myints+3, myints+6));
	triangle.push_back(vector<int>(myints+6, myints+10));

	cout << minimumTotal(triangle) << endl;
	cout << minimumTotal(empty) << endl;

	return 0;
}
