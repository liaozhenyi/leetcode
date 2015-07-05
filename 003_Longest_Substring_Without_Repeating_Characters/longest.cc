/**********************************************************************

 Given a string, find the length of the longest substring without repeating 
 characters. For example, the longest substring without repeating letters 
 for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest 
 substring is "b", with the length of 1.

**********************************************************************/

int lengthOfLongestSubstring(string s) {
	vector<int> charLastPos = vector<int>(128, -1);
	vector<int> length;
	int sentinelIdx = -1, maxLen = 0;

	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		if (sentinelIdx < charLastPos[c])
			sentinelIdx = charLastPos[c];
		int len = i - sentinelIdx;
		if (len > maxLen)
			maxLen = len;
		
		charLastPos[c] = i;
	}

	return maxLen;
}
