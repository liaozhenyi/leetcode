/**********************************************************************

 Given a string s, partition s such that every substring of the partition
 is a palindrome.

 Return the minimum cuts needed for a palindrome partitioning of s.
 
 For example, given s = "aab",
 Return 1 since the palindrome partitioning ["aa","b"] could be produced 
 using 1 cut.

**********************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int minCut(string s) {
	int sLen, ans;
	int start, end, dis, sum;
	int *partition, **palindrome;

	sLen = s.size();
	if (!sLen)
		return 0;

	partition = new int[sLen];
	palindrome = new int*[sLen];
	for (int i = 0; i < sLen; i++)
		palindrome[i] = new int[sLen];

/*
 *  Time complexity O(n^3), Get "Time Limit Exceeded" error!
 *
	for (dis = 0; dis < sLen; dis++)
		for (start = 0; start < sLen-dis; start++) {
			end = start+dis;
			if (start == end) {
				palindrome[start][end] = 1;
			} else if (start+1 == end) {
				palindrome[start][end] = (s[start] == s[end]);
			} else {
				palindrome[start][end] = (s[start] == s[end]) \
						& palindrome[start+1][end-1];
			}

			if (palindrome[start][end]) {
				partition[start][end] = 1;
			} else {
				partition[start][end] = INT_MAX;
				for (int i = start; i < end; i++) {
					sum = partition[start][i] + partition[i+1][end];
					if (sum < partition[start][end])
						partition[start][end] = sum;
					if (partition[start][end] == 2)
						break;
				}
			}
		}
 */

	for (dis = 0; dis < sLen; dis++)
		for (start = 0; start < sLen-dis; start++) {
			end = start+dis;
			if (start == end) {
				palindrome[start][end] = 1;
			} else if (start+1 == end) {
				palindrome[start][end] = (s[start] == s[end]);
			} else {
				palindrome[start][end] = (s[start] == s[end]) \
						& palindrome[start+1][end-1];
			}
				
		}
	for (start = 0, end = 0; end < sLen; end++) {
		if (start == end) {
			partition[end] = 1;
		} else {
			if (palindrome[start][end]) {
				partition[end] = 1;
			} else {
				partition[end] = partition[end-1]+1;
				for (int i = start; i < end; i++) {
					if (!palindrome[i+1][end])
						continue;
					if (partition[i]+1 < partition[end])
						partition[end] = partition[i]+1;
				}
			}
		}
	}

	ans = partition[sLen-1]-1;

	for (int i = 0; i < sLen; i++)
		delete[]palindrome[i];
	delete[]palindrome;
	delete[]partition;

	return ans;
}

int main(int argc, char *argv[])
{
	string s1 ("abbababba");
	string s2 ("abbabaab");
	string s3 ("abcdefg");
	string s4 ("");

	cout << minCut(s1) << endl;
	cout << minCut(s2) << endl;
	cout << minCut(s3) << endl;
	cout << minCut(s4) << endl;
	cout << minCut(string ("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")) << endl;

	return 0;
}
