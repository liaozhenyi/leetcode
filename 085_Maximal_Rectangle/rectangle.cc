/**********************************************************************

 Given a 2D binary matrix filled with 0's and 1's, find the largest 
 rectangle containing all ones and return its area.

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int maximalRectangle(vector<vector<char> > &matrix) {
	int ans = 0;
	vector<vector<int> > maxOnes;

	if (!matrix.size() || !matrix[0].size())
		return 0;

	for (int j = 0; j < matrix[0].size(); j++)
		maxOnes.push_back(vector<int>(matrix[0].size(), 0));

	for (int i = 0; i < matrix.size(); i++)	{
	/*	for (int j = 0; j < matrix[i].size(); j++) {
			for (int k = j; k < matrix[i].size(); k++) {
				cout << maxOnes[j][k] << " ";
			}
			cout << endl;
		} */

		for (int j = 0; j < matrix[i].size(); j++)
			for (int k = j; k < matrix[i].size(); k++) {
				if (matrix[i][k] == '1') {
					maxOnes[j][k] += (k-j+1);
					continue;
				}
				while (k < matrix[i].size()) {
					if (ans < maxOnes[j][k])
						ans = maxOnes[j][k];
					maxOnes[j][k] = 0;
					++k;
				}
			}
	}
	for (int i = 0; i < matrix[0].size(); i++)
		for (int j = i; j < matrix[0].size(); j++)
			if (ans < maxOnes[i][j])
				ans = maxOnes[i][j];


	return ans;
}

int main(int argc, char *argv[])
{
	char str1[] = {'1','1','1','1','1','0','0','1','0','0','1','1','0','1','1'};
	vector<vector<char> > matrix1, matrix2, matrix3;
	
	matrix1.push_back(vector<char>(str1, str1+3));
	matrix1.push_back(vector<char>(str1+3, str1+6));
	matrix1.push_back(vector<char>(str1+6, str1+9));
	matrix1.push_back(vector<char>(str1+9, str1+12));
	matrix1.push_back(vector<char>(str1+12, str1+15));

	matrix2.push_back(vector<char>(str1, str1+3));
	matrix2.push_back(vector<char>(str1+3, str1+6));
	matrix2.push_back(vector<char>(str1+6, str1+9));

	matrix3.push_back(vector<char>(str1+6, str1+7));

	cout << maximalRectangle(matrix1) << endl;
	cout << maximalRectangle(matrix2) << endl;
	cout << maximalRectangle(matrix3) << endl;

	return 0;
}
