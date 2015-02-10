/**********************************************************************

 Given a string s and a dictionary of words dict, determine if s can be 
 segmented into a space-separated sequence of one or more dictionary words.

 For example, given
 s = "leetcode",
 dict = ["leet", "code"].
 
 Return true because "leetcode" can be segmented as "leet code".

**********************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
	vector<int> separateIndex;
	vector<int>::const_iterator iter;
	unordered_set<string>::const_iterator got;

	separateIndex.push_back(-1);
	for (int i = 0; i < s.size(); i++) {
		for (iter = separateIndex.begin(); iter != separateIndex.end(); iter++) {
			string substr = string(s, *iter+1, i-*iter);
			got = dict.find(substr);
			if (got != dict.end()) {
				separateIndex.push_back(i);
				break;
			}
		}
	}

	return separateIndex[separateIndex.size()-1] == s.size()-1 ? true : false;
}

int main(int argc, char *argv[])
{
	unordered_set<string> dict;
	string s1 = string("leetcode");
	string s2 = string("leecod");
	string s3 = string("leeetecode");
	string s4 = string("leetecod");
	string s5 = string("leeeteetecod");

	dict.insert(string("lee"));
	dict.insert(string("leet"));
	dict.insert(string("ete"));
	dict.insert(string("cod"));
	dict.insert(string("code"));

	cout << wordBreak(s1, dict) << endl;
	cout << wordBreak(s2, dict) << endl;
	cout << wordBreak(s3, dict) << endl;
	cout << wordBreak(s4, dict) << endl;
	cout << wordBreak(s5, dict) << endl;
	cout << wordBreak(string(), dict) << endl;
	
	return 0;
}
