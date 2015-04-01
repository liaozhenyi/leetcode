/**********************************************************************

 Given a column title as appear in an Excel sheet, return its corresponding column number.

 For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

**********************************************************************/

int titleToNumbers(string s) {
	int ans = 0;

	for (int i = 0; i < s.size(); i++) {
		ans = ans*26+(s[i]-'A')+1;
	}

	return ans;
}
