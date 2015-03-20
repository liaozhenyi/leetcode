/**********************************************************************

 Given a 2D board and a word, find if the word exists in the grid.

 The word can be constructed from letters of sequentially adjacent cell,
 where "adjacent" cells are those horizontally or vertically neighboring. 
 The same letter cell may not be used more than once.

 For example,
 Given board =
 
 [
   ["ABCE"],
   ["SFCS"],
   ["ADEE"]
 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false. 
 
**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

const int MOVE[][2] = {
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

bool visit(vector<vector<char> > &board, \
	vector<vector<bool> > &visited, int col, int row, string word) {
	if (col < 0 || col >= board.size() || \
		row < 0 || row >= board[col].size() || \
		visited[col][row] || \
		board[col][row] != word[0])
		return false;
	if (word.size() == 1)
		return true;

	visited[col][row] = true;
	int nextCol, nextRow;
	string subWord = string(word, 1, word.size()-1);

	for (int i = 0; i < 4; i++) {
		nextCol = col+MOVE[i][0];
		nextRow = row+MOVE[i][1];
		if (visit(board, visited, nextCol, nextRow, subWord))
			return true;
	}

	visited[col][row] = false;
	return false;
}

bool exist(vector<vector<char> > &board, string word) {
	vector<vector<bool> > visited;

	if (!word.size())
		return true;

	for (int i = 0; i < board.size(); i++)
		visited.push_back(vector<bool>(board[i].size(), false));

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (visit(board, visited, i, j, word))
				return true;
		}
	}

	return false;
}

int main(int argc, char *argv[])
{
	char str[] = "ABCESFCSADEE";
	vector<vector<char> > board;

	board.push_back(vector<char>(str, str+4));
	board.push_back(vector<char>(str+4, str+8));
	board.push_back(vector<char>(str+8, str+12));

	cout << exist(board, "ABFSAB") << endl;
	cout << exist(board, "CCEDASABF") << endl;
	cout << exist(board, "") << endl;
	cout << exist(board, "ESEEDASABCCF") << endl;

	return 0;
}
