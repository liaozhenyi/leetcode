/**********************************************************************

 Given a string s and a dictionary of words dict, add spaces in s to 
 construct a sentence where each word is a valid dictionary word.

 Return all such possible sentences.
 
 For example, given
 s = "catsanddog",
 dict = ["cat", "cats", "and", "sand", "dog"].
 
 A solution is ["cats and dog", "cat sand dog"].

**********************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
 * One solution, but use dfs we need to fix same problems repeatly,
 * HAHA, the OJ returns a "Time Limit Exceeded“ ERROR!
 */
/*
vector<string> dfs(vector<string> &ans, string s, \
		vector<vector<int> > &wordIndex, vector<int> path) {
	int idx;
	string solution;

	if (!path.size())
		idx = 0;
	else
		idx = *path.rbegin()+1;
	if (idx == s.size()) {
		solution = string(s, 0, path[0]+1);
		for (int j = 1; j < path.size(); j++) {
			solution.append(string(" "));
			solution.append(string(s, path[j-1]+1, path[j]-path[j-1]));
		}
		ans.push_back(solution);
		return ans;
	}
	for (int i = 0; i < wordIndex[idx].size(); i++) {
		path.push_back(wordIndex[idx][i]);
		dfs(ans, s, wordIndex, path);
		path.pop_back();
	}
	return ans;
}

vector<string> wordBreak(string s, unordered_set<string> &dict) {
	vector<int> wordEnd;
	vector<vector<int> > wordIndex;
	vector<string> ans;

	// get the index of all possible word ending position
	wordEnd.push_back(-1);
	for (int i = 0; i < s.size(); i++) {
		wordIndex.push_back(vector<int>());
		for (int j = 0; j < wordEnd.size(); j++) {
			string sub = string(s, wordEnd[j]+1, i-wordEnd[j]);
			if (dict.find(sub) != dict.end()) {
				wordIndex[wordEnd[j]+1].push_back(i);
				if (*wordEnd.rbegin() != i)
					wordEnd.push_back(i);
			}
		}
	}

	dfs(ans, s, wordIndex, vector<int>());
	return ans;
}
*/

/*
 * Still get a "Time Limit Exceeded" ERROR! AHA!!
 * IT's time to use some tricks to make things work!
 */
vector<string> wordBreak(string s, unordered_set<string> &dict) {
	int idx, round;
	string newSolution;
	vector<int> wordEnd, wordBegin;
	vector<int>::iterator it;
	vector<vector<string> > solution(s.size(), vector<string>());

	if (!s.size())
		return vector<string> ();

	// not elegent!
	wordBegin.push_back(s.size());
	for (int i = s.size()-1; i >= 0; i--) {
		round = wordBegin.size();
		for (int j = 0; j < round; j++) {
			idx = wordBegin[j]-1;
			string sub = string(s, i, idx-i+1);
			if (dict.find(sub) != dict.end()) {
				wordBegin.push_back(i);
				break;
			}
		}
	}

	if (*wordBegin.rbegin() != 0)
		return vector<string> ();
	
	wordEnd.push_back(-1);
	for (int i = 0; i < s.size(); i++) {
		solution.push_back(vector<string>());
		round = wordEnd.size();
		for (int j = 0; j < round; j++) {
			idx = wordEnd[j]+1;
			string sub = string(s, idx, i-idx+1);
			if (dict.find(sub) != dict.end()) {
				if (*wordEnd.rbegin() != i)
					wordEnd.push_back(i);
				if (!idx) {
					solution[i].push_back(sub);
				} else { // otherwise solution[idx-1].size() > 0
					sub = string(" ").append(sub);
					for (int k = 0; k < solution[idx-1].size(); k++) {
						newSolution = solution[idx-1][k];
						newSolution.append(sub);
						solution[i].push_back(newSolution);
					}
				}
			}
		}
	}

/*	for (int i = 0; i < solution.size(); i++) {
		cout << i << "*: ";
		for (int j = 0; j < solution[i].size(); j++) {
			cout << solution[i][j] << " | ";
		}
		cout << endl;
	}
*/
	return solution[s.size()-1];
}

int main(int argc, char *argv[])
{
	vector<string> ans;
	unordered_set<string> dict;
	string s1 = string("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
	string s2 = string("leecod");
	string s3 = string("leeetecode");
	string s4 = string("leetecod");
	string s5 = string("leeeteetecod");

	dict.insert(string("l"));
	dict.insert(string("e"));
	dict.insert(string("lee"));
	dict.insert(string("leet"));
	dict.insert(string("ete"));
	dict.insert(string("cod"));
	dict.insert(string("code"));

	dict.insert(string("a"));
	dict.insert(string("aa"));
	dict.insert(string("aaa"));
	dict.insert(string("aaaa"));
	dict.insert(string("aaaaa"));
	dict.insert(string("aaaaaa"));
	dict.insert(string("aaaaaaa"));
	dict.insert(string("aaaaaaaa"));
	
	ans = wordBreak(s1, dict);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	cout << endl;

	ans = wordBreak(s2, dict);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	cout << endl;

	ans = wordBreak(s3, dict);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	cout << endl;

	ans = wordBreak(s4, dict);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	cout << endl;
	
	ans = wordBreak(s5, dict);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	cout << endl;

	return 0;
}
