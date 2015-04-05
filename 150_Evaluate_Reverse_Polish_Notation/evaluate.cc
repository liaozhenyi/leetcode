/**********************************************************************

 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

 Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 
 Some examples:
   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

**********************************************************************/

/*
 * using a stack to do the calculation
 */
int str2int(string &s) {
	int num = 0;
	int sign = 1;

	for (auto c: s) {
		if (c == '-')
			sign *= -1;
		else
			num = num*10+(c-'0');
	}
	return num*sign;
}

int evalRPN(vector<string> &tokens) {
	stack<int> val;
	int top1, top2;

	for (auto &s: tokens) {
		if (s == string("+") || s == string("-") || \
			s == string("*") || s == string("/")) {
			top1 = val.top(); 
			val.pop();
			top2 = val.top();
			val.pop();

			if (s == string("+"))
				val.push(top2+top1);
			else if (s == string("-"))
				val.push(top2-top1);
			else if (s == string("*"))
				val.push(top2*top1);
			else
				val.push(top2/top1);
		} else {
			val.push(str2int(s));
		}
	}
	return val.top();
}
