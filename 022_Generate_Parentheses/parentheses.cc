/**********************************************************************

 Given n pairs of parentheses, write a function to generate all combinations 
 of well-formed parentheses.

 For example, given n = 3, a solution set is:
 
 "((()))", "(()())", "(())()", "()(())", "()()()"

***********************************************************************/

/*
 * 假定当s为合法括号对时q(s)为真
 * f(n)为所有n对括号的组合中满足q的组合数，令f(0)=1
 * p(n)为所有n对括号的组合中最外面为一对括号且满足q的组合数，p(n)=f(n-1)
 * 
 * 考虑第一个左括号内包含的括号对数，可能为1,2,3, ..., n
 * f(n) = f(0)*p(n) + f(2)*p(n-2) + ... + f(n-1)*p(1)
 *
 */

vector<string> generateParenthesis(int n) {
	vector<vector<string> > parentheses = vector<vector<string> >(n+1, vector<string>());

	if (0 == n)
		return parentheses[0];

	parentheses[0].push_back(string(""));
	parentheses[1].push_back(string("()"));
	
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			for (auto &s1: parentheses[i-j-1])
				for (auto &s2: parentheses[j])
					parentheses[i].push_back("("+s1+")"+s2);
		}
	}

	return parentheses[n];
}

