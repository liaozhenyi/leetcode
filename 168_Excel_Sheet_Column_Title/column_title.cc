/**********************************************************************

 Given a positive integer, return its corresponding column title as appear in an Excel sheet.

 For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

**********************************************************************/

string rotate(string &s) {
	int low = -1, high = s.size();

	while (++low < --high) {
		if (s[low] == s[high])
			continue;
		s[low] ^= s[high];
		s[high] ^= s[low];
		s[low] ^= s[high];
	}
	return s;
}

string convertToTitle(int n) {
	string s;
	char ch;

	assert(n > 0);

	while (n) {
		--n;
		ch = 'A'+n%26;
		n /= 26;
		s.push_back(ch);
	}

	return rotate(s);
}
