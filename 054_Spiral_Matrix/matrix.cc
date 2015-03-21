/**********************************************************************

 Given a matrix of m x n elements (m rows, n columns), return all elements 
 of the matrix in spiral order.

 For example,
 Given the following matrix:
 
 [
  [ 1, 2, 3 ],
  [ 4, 5, 6 ],
  [ 7, 8, 9 ]
 ]
 You should return [1,2,3,6,9,8,7,4,5].

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

const int direction[4][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};

vector<int> spiralOrder(vector<vector<int> > &matrix) {
	int direct;
	int curCol, curRow, colEleLeft, rowEleLeft;
	vector<int> ans;

	curCol = 0;
	curRow = -1;
	direct = 0;

	if (!(rowEleLeft = matrix.size()) || \
		!(colEleLeft = matrix[0].size()))
		return ans;

	while (colEleLeft && rowEleLeft) {
		if (direct%2) {
			for (int i = 0; i < rowEleLeft; ++i) {
				curCol += direction[direct][0];
				curRow += direction[direct][1];
				ans.push_back(matrix[curCol][curRow]);
			}
			--colEleLeft;
		} else {
			for (int i = 0; i < colEleLeft; ++i) {
				curCol += direction[direct][0];
				curRow += direction[direct][1];
				ans.push_back(matrix[curCol][curRow]);
			}
			--rowEleLeft;
		}
		direct = (direct == 3 ? 0 : direct+1);
	}

	return ans;
}

void showOrder(vector<int> &order) {
	cout << "size: " << order.size() << endl;
	for (int i = 0; i < order.size(); i++)
		cout << order[i] << " ";
	cout << endl;
}

int main(int argc, char *argv[])
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	vector<vector<int> > matrix;
	vector<int> ans;

	matrix.push_back(vector<int>(arr, arr+10));
	matrix.push_back(vector<int>(arr+10, arr+20));
	ans = spiralOrder(matrix);
	showOrder(ans);

	matrix.erase(matrix.begin(), matrix.end());
	matrix.push_back(vector<int>(arr, arr+5));
	matrix.push_back(vector<int>(arr+5, arr+10));
	matrix.push_back(vector<int>(arr+10, arr+15));
	matrix.push_back(vector<int>(arr+15, arr+20));
	ans = spiralOrder(matrix);
	showOrder(ans);

	return 0;
}
