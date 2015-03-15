/**********************************************************************

 Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

 The Sudoku board could be partially filled, where empty cells are filled 
 with the character '.'.

 A valid Sudoku board (partially filled) is not necessarily solvable. Only 
 the filled cells need to be validated.

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char> > &board) {
	vector<vector<char> >::iterator colIt;
	vector<char>::iterator rowIt;

	if (board.size() != 9 || board[0].size() != 9)
		return false;
	
	for (int i = 0; i < board.size(); i++) {
		vector<int> hash = vector<int>(10, 0);
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == '.')
				continue;
			int num = board[i][j] - '0';
			if (num > 9 || num < 1)
				return false;
			if (hash[num])
				return false;
			++hash[num];
		}
	}
	
	for (int j = 0; j < board[0].size(); j++) {
		vector<int> hash = vector<int>(10, 0);
		for (int i = 0; i < board.size(); i++) {
			if (board[i][j] == '.')
				continue;
			int num = board[i][j] - '0';
			if (num > 9 || num < 1)
				return false;
			if (hash[num])
				return false;
			++hash[num];
		}
	}

	for (int i = 0; i < board.size(); i+=3) {
		for (int j = 0; j < board[i].size(); j+=3) {
			vector<int> hash = vector<int>(10, 0);
			for (int m = i; m < i+3; m++) {
				for (int n = j; n < j+3; n++) {
					if (board[m][n] == '.')
						continue;
					int num = board[m][n] - '0';
					if (num > 9 || num < 1)
						return false;
					if (hash[num])
						return false;
					++hash[num];

				}
			}
		}
	}

	return true;
}

int main(int argc, char *argv[])
{
	char arr[] = "53..7....6..195....98....6.8...6...34..8.3..17...2...6.6....28....419..5....8..79";
	vector<vector<char> > board;

	for (int i = 9; i < sizeof(arr); i+=9)
		board.push_back(vector<char>(arr+i-9, arr+i));

	cout << isValidSudoku(board) << endl;
	
	return 0;
}
