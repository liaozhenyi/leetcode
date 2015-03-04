/**********************************************************************

 Given a string S and a string T, count the number of distinct subsequences 
 of T in S.

 A subsequence of a string is a new string which is formed from the original 
 string by deleting some (can be none) of the characters without disturbing 
 the relative positions of the remaining characters. (ie, "ACE" is a 
 subsequence of "ABCDE" while "AEC" is not).
 
 Here is an example:
 S = "rabbbit", T = "rabbit"
 
 Return 3.

**********************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numDistinct(string S, string T) {
	int count, ans;
	vector<vector<int> > distincts, temp;
	vector<vector<int> >::iterator it;

	if (S.size() < T.size())
		return 0;
	if (S == T)
		return 1;
	if (!T.size())
		return 1;

/*	for (int j = 0; j < S.size(); j++) {
		if (S[j] == T[0]) {
			distincts.push_back(vector<int>());
			distincts.rbegin()->push_back(j);
			distincts.rbegin()->push_back(1); // count 
		}
	}*/
	distincts.push_back(vector<int>());
	distincts.rbegin()->push_back(-1);
	distincts.rbegin()->push_back(1); // count 


	for (int i = 0; i < T.size(); i++) {
		if (!distincts.size())
			return 0;
		temp = distincts;
		distincts.erase(distincts.begin(), distincts.end());

		for (int j = 0; j < S.size(); j++) {
			if (T[i] != S[j])
				continue;
			count = 0;
			for (it = temp.begin(); it != temp.end(); it++) {
				if ((*it)[0] < j)
					count += (*it)[1];
			}
			if (count) {
				distincts.push_back(vector<int>());
				distincts.rbegin()->push_back(j);
				distincts.rbegin()->push_back(count);
			}
		}
	}
	
	ans = 0;
	for (it = distincts.begin(); it != distincts.end(); it++)
		ans += (*it)[1];
	return ans;
}

int main(int argc, char *argv[])
{
	cout << numDistinct("", "") << endl;
	cout << numDistinct("s", "") << endl;
	cout << numDistinct("rabbbit", "rabbit") << endl;
	cout << numDistinct("rabbit", "rabbbit") << endl;
	cout << numDistinct("rabbabbbiabit", "rabbit") << endl;

	return 0;
}
