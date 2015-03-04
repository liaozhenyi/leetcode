/**********************************************************************

 Given a string containing just the characters '(' and ')', find the 
 length of the longest valid (well-formed) parentheses substring.

 For "(()", the longest valid parentheses substring is "()", which has 
 length = 2.

 Another example is ")()())", where the longest valid parentheses substring 
 is "()()", which has length = 4.

**********************************************************************/

#include <iostream>
#include <string>

using namespace std;

int longestValidParentheses(string s) {
	int ans, idx;
	int *match = new int[s.size()];

	for (int i = 0; i < s.size(); i++) {
		match[i] = -1;
		if (s[i] == ')') {
			idx = i-1;
			while (idx >= 0) {
				if (match[idx] != -1) {
					idx = match[idx]-1;
					continue;
				}
				if (idx >= 0 && s[idx] == '(')
					match[i] = idx;
				break;
			}
		}
	}

	ans = 0;
	for (int i = s.size()-1; i > 0; ) {
		idx = i;
		while (idx > 0 && match[idx] != -1) {
			idx = match[idx]-1;
		}
		if (ans < i-idx)
			ans = i-idx;
		i = idx-1;
	}
	delete []match;
	return ans;
}

int main(int argc, char *argv[])
{
	cout << longestValidParentheses(string("")) << endl;
	cout << longestValidParentheses(string(")")) << endl;
	cout << longestValidParentheses(string(")))")) << endl;
	cout << longestValidParentheses(string("(((())))")) << endl;
	cout << longestValidParentheses(string(")()())")) << endl;
	cout << longestValidParentheses(string(")(())")) << endl;

	return 0;
}
