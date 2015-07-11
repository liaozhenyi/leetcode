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

/*
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
*/

/* 2nd round */
// TODO: when I use s.size() and p.size(), I can't get the right result,
// But when I change them to sLen and pLen, it functions well. 
// How would this be happened?
bool isMatch(string s, string p) {
	int sLen = s.size(), pLen = p.size();
	int starCnt = 0;

	for (auto c: p) {
		if (c == '*')
			++starCnt;
	}
	if (pLen-2*starCnt > sLen)
		return false;

	vector<int> matchPrev, matchCur;
	matchPrev.push_back(-1);
	for (int i = 0; i < pLen; ++i) {
		if (p[i] == '*') {
			continue;
		} else if (p[i] == '.' && p[i+1] != '*') {
			for (auto n: matchPrev) {
				if (n+1 < sLen)
					matchCur.push_back(n+1);
			}
		} else if (p[i] == '.' && p[i+1] == '*') {
			for (int j = matchPrev[0]; j < sLen; ++j)
				matchCur.push_back(j);
			++i;
		} else if (p[i+1] == '*') {
			for (int j = 0; j < matchPrev.size(); ++j) {
				if (matchCur.size() && (matchPrev[j] < matchCur.back()))
					continue;
				matchCur.push_back(matchPrev[j]);
				for (int k = matchPrev[j]+1; k < sLen; ++k) {
					if (s[k] != p[i])
						break;
					matchCur.push_back(k);
				}
			}
			++i;
		} else {
			for (auto n: matchPrev) {
				if (n+1 < sLen && s[n+1] == p[i])
					matchCur.push_back(n+1);
			}
		}

		matchPrev = matchCur;
		matchCur.erase(matchCur.begin(), matchCur.end());
		if (0 == matchPrev.size())
			return false;
	}
	
	return matchPrev.back() == sLen-1;
}
