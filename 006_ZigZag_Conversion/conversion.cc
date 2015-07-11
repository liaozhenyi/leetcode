/**********************************************************************

 The string "PAYPALISHIRING" is written in a zigzag pattern on a given 
 number of rows like this: (you may want to display this pattern in a 
 fixed font for better legibility)

 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string and make this conversion given a number of rows:
 
 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

***********************************************************************/


string convert(string s, int numRows) {
	int len = s.size();
	vector<string> matrix = vector<string>(numRows, string());

	if (1 == numRows)
		return s;

	int row = 0;
	int direction = 1;
	for (int i = 0; i < len; ) {
		matrix[row].push_back(s[i++]);

		if (direction == 1) {
			if (++row == numRows) {
				row = numRows-2;
				direction = 0;
			}
		} else {
			if (--row == -1) {
				row = 1;
				direction = 1;
			}
		}
	}

	string ans;
	for (int i = 0; i < numRows; ++i)
		ans.append(matrix[i]);
	return ans;
}

