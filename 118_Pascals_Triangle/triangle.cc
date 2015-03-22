/**********************************************************************

 Given numRows, generate the first numRows of Pascal's triangle.

 For example, given numRows = 5,
 Return
 
 [
      [1],
     [1,1],
    [1,2,1],
   [1,3,3,1],
  [1,4,6,4,1]
 ]

**********************************************************************/

/*
 * Use the previous line array to generate the next line.
 */
vector<vector<int> >generate(int numRows) {
	vector<vector<int> > ans;
	vector<int> cur;

	for (int i = 0; i < numRows; i++) {
		for (int j = cur.size()-1; j > 0; j--) {
			cur[j] += cur[j-1];
		}
		cur.push_back(1);
		ans.push_back(cur);
	}

	return ans;
}
