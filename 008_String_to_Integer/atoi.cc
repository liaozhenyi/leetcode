/**********************************************************************

 Implement atoi to convert a string to an integer.

***********************************************************************/

/*
 * possible input cases:
 * 	1) valid integer/double number
 * 	2) invalid str contain non-number character
 */

int myAtoi(string str) {
	int i;
	long num = 0;
	int sign = 1;

	for (i = 0; i < str.size(); ++i) {
		if (str[i] != ' ')
			break;
	}
	if (str[i] == '-') {
		sign = -1;
		++i;
	} else if (str[i] == '+') {
		++i;
	}
	
	while (i < str.size()) {
		if (str[i] > '9' || str[i] < '0')
			break;
		num = num*10 + str[i]-'0';
		if (num + INT_MIN > 0)
			break;
		++i;
	}

	num *= sign;
	if (num > INT_MAX) {
		return INT_MAX;
	} else if (num < INT_MIN) {
		return INT_MIN;
	} else {
		return num;
	}
}
