/**********************************************************************

 Given a m x n matrix, if an element is 0, set its entire row and column 
 to 0. Do it in place.

**********************************************************************/

/*
 * The trap: If you find a zero element, and set its entire row 
 * and column immediately. It may influence the judge of later
 * element because of their value may be changed.
 *
 * Method One, using another matrix' to record the value, and
 * the space complexity is O(m*n);
 * Method Two, record which column|row has 0 element, the space
 * complexity is O(m+n);
 * Method Three, when judge matrix[i][j], matrix[i][0] and matrix[0][j]
 * had been judged, so we can use [i][0] and [0][j] to record,
 * matrix[0][0] can used by [0][j] and [i][0], we need two extra space,
 * time complexity is O(1).
 */

void setZeroes(vector<vector<int> > &matrix) {
	int colSize, rowSize;
	bool zeroCol = false, zeroRow = false;

	if (!(colSize = matrix.size()) || \
		!(rowSize = matrix[0].size()))
		return ;

	for (int i = 0; i < colSize; i++) {
		for (int j = 0; j < rowSize; j++) {
			if (!matrix[i][j]) {
				if (!i) {
					zeroCol = true;
				} else {
					matrix[i][0] = 0;
				}
				if (!j) {
					zeroRow = true;
				} else {
					matrix[0][j] = 0;
				}
			}
		}
	}

	for (int i = 1; i < colSize; i++) {
		if (!matrix[i][0]) {
			for (int j = 1; j < rowSize; j++)
				matrix[i][j] = 0;
		}
	}
	if (zeroRow) {
		for (int i = 0; i < colSize; i++)
			matrix[i][0] = 0;
	}
	for (int j = 1; j < rowSize; j++) {
		if (!matrix[0][j]) {
			for (int i = 1; i < colSize; i++)
				matrix[i][j] = 0;
		}
	}
	if (zeroCol) {
		for (int j = 0; j < rowSize; j++)
			matrix[0][j] = 0;
	}
}
