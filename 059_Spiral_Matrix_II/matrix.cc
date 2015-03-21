/**********************************************************************

 Given an integer n, generate a square matrix filled with elements from 
 1 to n2 in spiral order.

 For example,
 Given n = 3,
 
 You should return the following matrix:
 [
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
 ]

**********************************************************************/

const int direction[4][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};

vector<vector<int> > generateMatrix(int n) {
	int direct, num;
	int curCol, curRow, colEleLeft, rowEleLeft;
	vector<vector<int> > ans;

	num = 0;
	curCol = 0;
	curRow = -1;
	direct = 0;
	colEleLeft = n;
	rowEleLeft = n;
	ans = vector<vector<int> >(n, vector<int>(n, 0));

	while (colEleLeft && rowEleLeft) {
		if (direct%2) {
			for (int i = 0; i < rowEleLeft; ++i) {
				curCol += direction[direct][0];
				curRow += direction[direct][1];
				ans[curCol][curRow] = ++num;
			}
			--colEleLeft;
		} else {
			for (int i = 0; i < colEleLeft; ++i) {
				curCol += direction[direct][0];
				curRow += direction[direct][1];
				ans[curCol][curRow] = ++num;
			}
			--rowEleLeft;
		}
		direct = (direct == 3 ? 0 : direct+1);
	}

	return ans;
}
