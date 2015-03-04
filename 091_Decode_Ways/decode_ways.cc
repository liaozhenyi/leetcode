/**********************************************************************

 A message containing letters from A-Z is being encoded to numbers using 
 the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given an encoded message containing digits, determine the total number 
 of ways to decode it.
 
 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 
 The number of ways decoding "12" is 2.

**********************************************************************/

#include <iostream>

using namespace std;

int numDecodings(string s) {
	int ans;
	int sLen = s.size();
	int *numDecodings = new int[sLen+1];

	if (!s.size())
		return 0;
	
	for (int i = 0; i <= sLen; i++) {
		if (!i) {
			numDecodings[i] = 1;
		} else if (i == 1) {
			numDecodings[i] = 0;
			if (s[i-1] != '0')
				numDecodings[i] = 1;
		} else {
			numDecodings[i] = 0;
			if (s[i-1] != '0')
				numDecodings[i] += numDecodings[i-1];
			if ((s[i-2] == '2' && s[i-1] < '7') || s[i-2] == '1')
				numDecodings[i] += numDecodings[i-2];
		}
	}

	ans = numDecodings[sLen];
	delete []numDecodings;
	return ans;
}

int main(int argc, char *argv[])
{
	cout << numDecodings(string("057")) << endl;
	cout << numDecodings(string("123620")) << endl;
	cout << numDecodings(string("")) << endl;
	cout << numDecodings(string("122222222222222222")) << endl;

	return 0;
}
