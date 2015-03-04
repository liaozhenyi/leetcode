/**********************************************************************

 Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 
 and s2.

 For example,
 Given:
 s1 = "aabcc",
 s2 = "dbbca",
 
 When s3 = "aadbbcbcac", return true.
 When s3 = "aadbbbaccc", return false.

**********************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
	int idx;
	vector<int> match, temp;
	
	if (s1.size()+s2.size() != s3.size())
		return false;
	if (!s3.size())
		return true;

	if (s1.size() && s1[0] == s3[0])
		match.push_back(0);
	if (s2.size() && s2[0] == s3[0])
		match.push_back(-1);
	if (!match.size())
		return false;

	for (int i = 1; i < s3.size(); i++) {
		temp = match;
		match.erase(match.begin(), match.end());
		for (int j = 0; j < temp.size(); j++) {
			idx = temp[j];	
			if (i-idx-1 < s2.size() && s2[i-idx-1] == s3[i])
				// without this, I got a "Memory Limit Exceeded" Error
				if (!match.size() || *match.rbegin() != idx)
					match.push_back(idx);
			if (idx+1 < s1.size() && s1[idx+1] == s3[i])
				match.push_back(idx+1);
		}
		if (!match.size())
			return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	string s1("");
	string s2("aabcc");
	string s3("dbbca");
	string s4("aadbbcbcac");
	string s5("aadbbbaccc");
	string s6("a");
	string s7("aaaaaaaaaa");
	string s8("aaaaaaaaaaaaaaaaaaaa");

	cout << isInterleave(s1, s1, s1) << endl;
	cout << isInterleave(s1, s2, s2) << endl;
	cout << isInterleave(s2, s1, s2) << endl;
	cout << isInterleave(s2, s3, s4) << endl;
	cout << isInterleave(s2, s3, s5) << endl;
	cout << isInterleave(s1, s6, s6) << endl;
	cout << isInterleave(s7, s7, s8) << endl;
	cout << isInterleave("a", "b", "ab") << endl;

	return 0;
}
