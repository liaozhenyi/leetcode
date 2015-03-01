/**********************************************************************

 '?' Matches any single character.
 '*' Matches any sequence of characters (including the empty sequence).
 
 The matching should cover the entire input string (not partial).
 
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 
 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "*") → true
 isMatch("aa", "a*") → true
 isMatch("ab", "?*") → true
 isMatch("aab", "c*a*b") → false

**********************************************************************/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool isMatch(const char *s, const char *p) {
	int sLen, pLen, star;
	vector<int> matchTemp, matchAns;

	sLen = strlen(s);
	pLen = strlen(p);
	star = count(p, p+pLen, '*');
	if (pLen-star > sLen)	return false;

	matchAns.push_back(0);

	for (int j = 0; j < pLen; j++) {
		matchTemp = matchAns;
		matchAns.erase(matchAns.begin(), matchAns.end());
		if (p[j] == '*') {
			for (int i = matchTemp[0]; i < sLen+1; i++)
				matchAns.push_back(i);
		} else if (p[j] == '?') {
			for (int i = 0; i < matchTemp.size(); i++)
				if (matchTemp[i]+1 <= sLen)
					matchAns.push_back(matchTemp[i]+1);
		} else {
			for (int i = 0; i < matchTemp.size(); i++)
				if (p[j] == s[matchTemp[i]] && matchTemp[i]+1 <= sLen)
					matchAns.push_back(matchTemp[i]+1);
		}
		if (!matchAns.size())
			return false;
	}

	return *matchAns.rbegin() == sLen;
}

int main(int argc, char *argv[])
{
	cout << isMatch("", "") << endl;
	cout << isMatch("", "*") << endl;
	cout << isMatch("a", "?*") << endl;
	cout << isMatch("aab", "*a") << endl;
	cout << isMatch("a", "") << endl;
	cout << isMatch("aab", "c*a*b") << endl;
	cout << isMatch("aa", "aaa") << endl;
	cout << isMatch("hi", "*?") << endl;

	return 0;
}
