/***************************************************************************
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, 
 * where "adjacent" cells are those horizontally or vertically neighboring. 
 * The same letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 *
 * [
 *  ["ABCE"],
 *  ["SFCS"],
 *  ["ADEE"]
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char> >&board, string word) {
		int colnum, rownum;
		vector<vector<char> >::iterator str;

		rownum = board.size();
		str = board.begin();
		colnum = str->size();
	
		vector<vector<bool> >path(rownum, vector<bool>(colnum, false));

		for (int i = 0; i < rownum; i++)
			for (int j = 0; j < colnum; j++)
				if (search(board, i, j, word, 0, path))
					return true;
		return false;
		
	}
private:
	bool search(vector<vector<char> >&board, int row, int col, \
			string word, int pos, vector<vector<bool> >&path) {
		int colnum, rownum;
		bool ans;
		vector<vector<char> >::iterator str;

		rownum = board.size();
		str = board.begin();
		colnum = str->size();

// The second error!
//		if (str->size() == pos)
		if (word.size() == pos)
			return true;

// First error!
//		if (path[row][col] == true)
//			return false;
//
		if (col < 0 || col >= colnum || \
			row < 0 || row >= rownum)
			return false;

		if (path[row][col] == true)
			return false;

		if (board[row][col] != word[pos])
			return false;

		pos++;
		path[row][col] = true;
		ans = search(board, row - 1, col, word, pos, path) || \
			search(board, row + 1, col, word, pos, path) || \
			search(board, row, col - 1, word, pos, path) || \
			search(board, row, col + 1, word, pos, path);
		path[row][col] = false;
		return ans;
	}
};

/**
 * Finally, accepted after 3 submissions.
 * Stay focus, think more about the edge case, 
 * before you do array operation, care about
 * whether the access will cause memory error!
 * When using functions or do comparison, care
 * about the args!
 */
