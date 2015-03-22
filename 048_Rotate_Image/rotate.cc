/**********************************************************************

 You are given an n x n 2D matrix representing an image.

 Rotate the image by 90 degrees (clockwise).
 
 Follow up:
 Could you do this in-place?

**********************************************************************/

/*
 * After the rotation, column i -> row n-1-i
 * 			row j -> column j
 * (i, j) -> (j, n-1-i)
 * (j, n-1-i) -> (n-1-i, n-1-j)
 * (n-1-i, n-1-j) -> (n-1-j, i)
 * (n-1-j, i) -> (i, j)
 */
void rotate(vector<vector<int> > &matrix) {
	int size;

	size = matrix.size();
	for (int i = 0; 2*i < size; i++) {
		for (int j = i; j < size-i-1; j++) {
			int tmp = matrix[size-1-j][i];
			matrix[size-1-j][i] = matrix[size-1-i][size-1-j];
			matrix[size-1-i][size-1-j] = matrix[j][size-1-i];
			matrix[j][size-1-i] = matrix[i][j];
			matrix[i][j] = tmp;
		}
	}
}
