/**********************************************************************

 Implement regular expression matching with support for '.' and '*'.

 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 
 The matching should cover the entire input string (not partial).
 
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 
 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "a*") → true
 isMatch("aa", ".*") → true
 isMatch("ab", ".*") → true
 isMatch("aab", "c*a*b") → true

**********************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool isMatch(const char *s, const char *p) {
	int sLen, pLen, star;
	vector<int> matchTemp, matchAns;

	sLen = strlen(s);
	pLen = strlen(p);
	star = count(p, p+pLen, '*');
	if (pLen-2*star > sLen)	return false;

	matchAns.push_back(0);

	for (int j = 0; j < pLen; j++) {
		matchTemp = matchAns;
		matchAns.erase(matchAns.begin(), matchAns.end());
		if (p[j] == '*') {
			matchAns = matchTemp;
		} else if (p[j] == '.' && p[j+1] == '*') {
			for (int i = matchTemp[0]; i <= sLen; i++)
				matchAns.push_back(i);
			j++;
		} else if (p[j] == '.' && p[j+1] != '*') {
			for (int i = 0; i < matchTemp.size(); i++)
				if (matchTemp[i]+1 <= sLen)
					matchAns.push_back(matchTemp[i]+1);
		} else if (p[j+1] == '*'){
			for (int i = 0; i < matchTemp.size(); i++) {
				if (matchAns.size() && matchTemp[i] <= matchAns[matchAns.size()-1])
					continue;
				matchAns.push_back(matchTemp[i]);
				for (int k = matchTemp[i]+1; k <= sLen; k++) {
					if (s[k-1] == p[j])
						matchAns.push_back(k);
					else
						break;
				}
			}
			j++;
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
	cout << isMatch("a", ".*") << endl;
	cout << isMatch("aab", "*a") << endl;
	cout << isMatch("a", "") << endl;
	cout << isMatch("aab", "c*a*b") << endl;
	cout << isMatch("aa", "aa*a*") << endl;
	cout << isMatch("hi", "*.") << endl;
	cout << isMatch("abcbcd", "ac*b*c*b*c*d") << endl;

	return 0;
}
