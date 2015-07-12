/**********************************************************************

 Given a roman numeral, convert it to an integer.

 Input is guaranteed to be within the range from 1 to 3999.

***********************************************************************/

int sym2val(char c) {
	switch(c) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
	}
}

int romanToInt(string s) {
	int num = 0;
	
	for (int i = 0; i < s.size(); ++i) {
		int val1 = sym2val(s[i]);
		if (0 == val1)
			continue;
		if (i+1 < s.size()) {
			int val2 = sym2val(s[i+1]);
			if (val1 < val2) {
				num += (val2-val1);
				++i;
				continue;
			}
		}
		num += val1;
	}
	return num;
}
