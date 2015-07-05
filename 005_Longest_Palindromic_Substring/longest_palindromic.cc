/**********************************************************************
 
 Given a string S, find the longest palindromic substring in S. You may 
 assume that the maximum length of S is 1000, and there exists one unique 
 longest palindromic substring. 

***********************************************************************/

/* Solution 1: 300ms!!! */
string longestPalindrome(string s) {
	int len = s.size();
	vector<int> palinIdxPrev, palinIdxCur;
	string ans;

	for (int i = 0; i < s.size(); ++i) {
		palinIdxCur.erase(palinIdxCur.begin(), palinIdxCur.end());
		for (auto idx: palinIdxPrev) {
			if (idx) {
				if (idx && s[idx-1] == s[i])
					palinIdxCur.push_back(idx-1);
			}
		}
		if (i && s[i-1] == s[i])
			palinIdxCur.push_back(i-1);
		palinIdxCur.push_back(i);

		if (i-palinIdxCur[0]+1 > ans.size())
			ans = s.substr(palinIdxCur[0], i-palinIdxCur[0]+1);
		palinIdxPrev = palinIdxCur;
	}

	return ans;
}


/* Solution 2: 12ms :) http://hihocoder.com/problemset/problem/1032 */
string addChar0(string &s) {
	string _s = string("0");

	for (auto &c: s) {
		_s.push_back(c);
		_s.push_back('0');
	}
	return _s;
}

string delChar0(string &_s) {
	string s;

	for (int i = 1; i < _s.size(); i+=2)
		s.push_back(_s[i]);
	return s;
}

static inline int getMin(int a, int b) {
	return a > b ? b : a;
}

string longestPalindrome(string s) {
	string _s = addChar0(s);
	int centerIdx, maxEdgeIdx;
	vector<int> maxLength = vector<int>(_s.size(), 0);

	centerIdx = 0;
	maxEdgeIdx = 0;
	maxLength[0] = 1;

	for (int i = 1; i < _s.size(); ++i) {
		int lowIdx, highIdx;
		if (maxEdgeIdx < i) {
			lowIdx = i;
			highIdx = i;
		} else {
			int minLength = getMin(maxLength[2*centerIdx-i], \
					maxLength[centerIdx] - 2*(i-centerIdx));
			lowIdx = i - (minLength-1)/2;
			highIdx = i + (minLength-1)/2;
		}

		while (1) {
			if (lowIdx < 0 || highIdx == _s.size() || _s[lowIdx] != _s[highIdx]) {
				++lowIdx;
				--highIdx;
				break;
			}
			--lowIdx;
			++highIdx;
		}
		if (highIdx > maxEdgeIdx) {
			maxEdgeIdx = highIdx;
			centerIdx = i;
		}
		maxLength[i] = highIdx - lowIdx + 1;
	}

	string _ans;
	for (int i = 0; i < _s.size(); ++i) {
		if (maxLength[i] > _ans.size()) {
			_ans = _s.substr(i - (maxLength[i]-1)/2, maxLength[i]);
		}
	}
	return delChar0(_ans);
}

