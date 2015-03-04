/**********************************************************************

 Given two words word1 and word2, find the minimum number of steps required 
 to convert word1 to word2. (each operation is counted as 1 step.)

 You have the following 3 operations permitted on a word:
 
 a) Insert a character
 b) Delete a character
 c) Replace a character

**********************************************************************/

#include <iostream>

using namespace std;

const int ARRAYSIZE = 1000;

inline int getMin(int a, int b, int c) {
	if (a < b)
		return a < c ? a : c;
	else
		return b < c ? b : c;
}

int minDistance(string word1, string word2) {
	int dist[2][ARRAYSIZE];

	for (int j = 0; j <= word2.size(); j++)
		dist[0][j] = j;
	for (int i = 1; i <= word1.size(); i++) {
		dist[i%2][0] = i;
		for (int j = 1; j <= word2.size(); j++) {
			if (word1[i-1] == word2[j-1]) {
				dist[i%2][j] = dist[(i-1)%2][j-1];
			} else {
				dist[i%2][j] = getMin(dist[i%2][j-1],\
					dist[(i-1)%2][j-1], dist[(i-1)%2][j])+1;
			}
		}
	}

	return dist[word1.size()%2][word2.size()];
}

int main(int argc, char *argv[])
{
	cout << minDistance(string("abc"), string("efc")) << endl;
	cout << minDistance(string(""), string("efc")) << endl;
	cout << minDistance(string("abc"), string("")) << endl;
	cout << minDistance(string(""), string("")) << endl;
	
	return 0;
}
