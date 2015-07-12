/**********************************************************************

 Write a function to find the longest common prefix string amongest an array of strings

***********************************************************************/

string longestCommonPrefix(vector<string> &strs) {
	int maxComPreLen = INT_MAX;
	string commonPrefix;

	if (!strs.size())
		return commonPrefix;

	for (auto &s: strs) {
		if (maxComPreLen > s.size())
			maxComPreLen = s.size();
	}

	commonPrefix = strs[0].substr(0, maxComPreLen);
	for (auto &s: strs) {
		int i;
		for (i = 0; i < maxComPreLen; ++i) {
			if (s[i] != commonPrefix[i])
				break;
		}
		maxComPreLen = i;
		commonPrefix = commonPrefix.substr(0, maxComPreLen);
	}

	return commonPrefix;
}
