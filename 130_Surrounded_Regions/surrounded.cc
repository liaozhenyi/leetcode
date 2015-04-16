/**********************************************************************

 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

 A region is captured by flipping all 'O's into 'X's in that surrounded region.
 
 For example,
 X X X X
 X O O X
 X X O X
 X O X X
 After running your function, the board should be:
 
 X X X X
 X X X X
 X X X X
 X O X X

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>> &board, int c, int r) {
	int col = board.size(), row = board[0].size();
	
	if (c < 1 || c >= col-1 || r < 1 || r >= row-1)
		return ;
	if (board[c][r] != 'O')
		return ;
	board[c][r] = 'W';
	dfs(board, c, r-1);
	dfs(board, c, r+1);
	dfs(board, c-1, r);
	dfs(board, c+1, r);
}

void handle(vector<vector<char>> &board) {
	for (auto &v: board) {
		for (auto &c: v) {
			if (c == 'W')
				c = 'O';
			else
				c = 'X';
		}
	}
}

void solve(vector<vector<char>> &board)
{
	if (3 > board.size() || 3 > board[0].size())
		return ;
	int col = board.size(), row = board[0].size();

	// (0, 0) -> (0, row-1) | (col-1, 0) -> (col-1, row-1)
	for (int i = 0; i < row; ++i) {
		if (board[0][i] == 'O') {
			board[0][i] = 'W';
			dfs(board, 1, i);
		}
		if (board[col-1][i] == 'O') {
			board[col-1][i] = 'W';
			dfs(board, col-2, i);
		}
	}
	// (0, 0) -> (col-1, 0) | (0, row-1) -> (col-1, row-1)
	for (int i = 0; i < col; ++i) {
		if (board[i][0] == 'O')	{
			board[i][0] = 'W';
			dfs(board, i, 1);
		}
		if (board[i][row-1] == 'O') {
			board[i][row-1] = 'W';
			dfs(board, i, row-2);
		}
	}
	handle(board);
}

int main(void)
{
	vector<vector<char>> region;

	region.push_back(vector<char>(3, 'O'));
	region.push_back(vector<char>(3, 'O'));
	region.push_back(vector<char>(3, 'O'));

	solve(region);

	for (auto v: region) {
		for (auto c: v)
			cout << c;
		cout << endl;
	}
}
