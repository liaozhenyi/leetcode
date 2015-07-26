/**********************************************************************

 Given a digit string, return all possible letter combinations that the number could represent.

 A mapping of digit to letters (just like on the telephone buttons) is given below.

 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

***********************************************************************/

vector<string> letterCombinations(string digits) {
	vector<string> ans;
	string strs[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	int totalCase = 1;
	for (auto &c: digits) {
		if (c == '0' || c == '1')
			continue;
		totalCase *= strs[c-'0'].size();
	}

	for (int i = 0; i < totalCase; ++i) {
		string cmb = string("");
		int num = i;
		for (auto &c: digits) {
			if (c == '0' || c == '1')
				continue;
			int strSize = strs[c-'0'].size();
			cmb.append(1, strs[c-'0'][num%strSize]);
			num /= strSize;
		}
		if (!cmb.empty())
			ans.push_back(cmb);
	}

	return ans;
}
