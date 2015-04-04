/**********************************************************************

 Compare two version numbers version1 and version2.
 If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 
 You may assume that the version strings are non-empty and contain only 
 digits and the . character.

 The . character does not represent a decimal point and is used to separate 
 number sequences.

 For instance, 2.5 is not "two and a half" or "half way to version three", 
 it is the fifth second-level revision of the second first-level revision.
 
 Here is an example of version numbers ordering:
 
 0.1 < 1.1 < 1.2 < 13.37

**********************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*
 * compare each major version number in order.
 */

/*
 * comparison based on the value
 */
int compareString(string &s1, string &s2) {
	string::iterator it;

//cout << "compare " << s1 << " " << s2 << endl;
	for (it = s1.begin(); it != s1.end(); it++)
		if (*it != '0')
			break;
	s1 = string(it, s1.end());
	for (it = s2.begin(); it != s2.end(); it++)
		if (*it != '0')
			break;
	s2 = string(it, s2.end());

	if (s1.size() > s2.size()) {
		return 1;
	} else if (s1.size() < s2.size()) {
		return -1;
	} else {
		for (decltype(s1.size()) i = 0; \
			i < s1.size(); i++) {
			if (s1[i] > s2[i])
				return 1;
			else if (s1[i] < s2[i])
				return -1;
		}
		return 0;
	}
}

int compareVersion(string version1, string version2) {
	int ans = 0;
	size_t pos1, pos2;
	string substr1, substr2;

	do {
		if (version1.empty()) {
			substr1 = string("0");
		} else {
			pos1 = version1.find('.');
			if (pos1 == string::npos) {
				substr1 = version1;
				version1 = string();
			} else {
				substr1 = string(version1, 0, pos1);
				version1 = string(version1, pos1+1, version1.size()-pos1-1);
			}
		}
		if (version2.empty()) {
			substr2 = string("0");
		} else {
			pos2 = version2.find('.');
			if (pos2 == string::npos) {
				substr2 = version2;
				version2 = string();
			} else {
				substr2 = string(version2, 0, pos2);
				version2 = string(version2, pos2+1, version2.size()-pos2-1);
			}
		}

		ans = compareString(substr1, substr2);
		if (0 != ans)
			return ans;
	} while (!version1.empty() || !version2.empty());

	if (version1.empty() && version2.empty())
		ans = 0;
	else if (version1.empty())
		ans = -1;
	else
		ans = 1;

	return ans;
}

int main(void)
{
	cout << compareVersion("", "") << endl;
	cout << compareVersion("1", "1.0") << endl;
	cout << compareVersion("1.1", "1.2") << endl;
	cout << compareVersion("1", "1.1") << endl;
	cout << compareVersion("1.2.3", "1.2.3") << endl;
	cout << compareVersion("127.0.0.1", "127.0.0.255") << endl;

	return 0;
}
