/**********************************************************************

 Given a string containing just the characters '(', ')', '{', '}', '[' 
 and ']', determine if the input string is valid.

 The brackets must close in the correct order, "()" and "()[]{}" are all
 valid but "(]" and "([)]" are not.

***********************************************************************/

bool isValid(string s) {
	std::stack<char> chStack;

	for (auto &c: s) {
		if (c == '(' || c == '{' || c == '[') {
			chStack.push(c);
		} else if (c == ')') {
			if (chStack.empty() || chStack.top() != '(')
				return false;
			chStack.pop();
		} else if (c == '}') {
			if (chStack.empty() || chStack.top() != '{')
				return false;
			chStack.pop();
		} else if (c == ']') {
			if (chStack.empty() || chStack.top() != '[')
				return false;
			chStack.pop();
		} else {
			return false;
		}
	}

	return chStack.empty();
}
