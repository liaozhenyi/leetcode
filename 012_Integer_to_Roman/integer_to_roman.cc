/**********************************************************************

 Given an integer, convert it to a roman numeral.

 Input is guaranteed to be within the range from 1 to 3999.

***********************************************************************/

string intToRoman(int num) {
	std::string romanStr;
	int n[] = {1000, 500, 100, 50, 10, 5, 1};
	string s = string("MDCLXVI");

	for (int i = 0; i < sizeof(n)/sizeof(int); i+=2) {
		if (num < n[i])
			continue;
		if (num >= 9*n[i]) {
			romanStr.push_back(s[i]);
			romanStr.push_back(s[i-2]);
			num -= 9*n[i];
		}
		if (num >= 5*n[i]) {
			romanStr.push_back(s[i-1]);
			num -= 5*n[i];
		}
		if (num >= 4*n[i]) {
			romanStr.push_back(s[i]);
			romanStr.push_back(s[i-1]);
			num -= 4*n[i];
		}
		while (num >= n[i]) {
			romanStr.push_back(s[i]);
			num -= n[i];
		}
	}

	return romanStr;
}
