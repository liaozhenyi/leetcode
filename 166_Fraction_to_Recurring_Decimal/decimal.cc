/**********************************************************************

 Given two integers representing the numerator and denominator of a fraction, 
 return the fraction in string format.

 If the fractional part is repeating, enclose the repeating part in parentheses.
 
 For example,
 
 Given numerator = 1, denominator = 2, return "0.5".
 Given numerator = 2, denominator = 1, return "2".
 Given numerator = 2, denominator = 3, return "0.(6)".

**********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cassert>

using namespace std;

/*
 * numerator == 0, calculation over
 * numerator >= denominator, get the integer part;
 * numerator < demominator, numerator = numerator*10%demoniator
 */
string fractionToDecimal(int numerator, int denominator) {
	bool decimalPart = false;
	string ans, dec;
	int sign = 1;
	char ch;
	long int numera, denomina, pre;
	vector<long int> remainder;
	vector<long int>::const_iterator it;

	assert(denominator);
	if (numerator < 0) {
		numera = (long int)0 - numerator;
		sign = -sign;
	} else {
		numera = numerator;
	}
	if (denominator < 0) {
		//denomina = -denominator;
		denomina = (long int)0 - denominator;
		sign = -sign;
	} else {
		denomina = denominator;
	}

	if (0 == numera)
		return string("0");

	if (sign == -1)
		ans.push_back('-');

	// integer part
	char integerStr[33];
	snprintf(integerStr, 33, "%ld", numera/denomina);
	ans += string(integerStr);
	numera %= denomina;

	// decimal part
	while (numera) {
		if (decimalPart == false) {
			ans.push_back('.');
			decimalPart = true;
		}

		it = find(remainder.begin(), remainder.end(), numera);
		if (it != remainder.end()) {
			dec.insert(dec.begin()+(it-remainder.begin()), '(');
			dec.push_back(')');
			break;
		}

		remainder.push_back(numera);
		pre = numera;
		numera *= (long int)10;
		ch = numera/denomina + '0';
		numera %= denomina;
		dec.push_back(ch);
	}
	ans += dec;
		
	return ans;
}

int main(void)
{
	cout << fractionToDecimal(0, -12) << endl;
	cout << fractionToDecimal(10, 3) << endl;
	cout << fractionToDecimal(1, -6) << endl;
	cout << fractionToDecimal(1, -1) << endl;
	cout << fractionToDecimal(INT_MAX, 1+INT_MIN) << endl;
	cout << fractionToDecimal(44, -66) << endl;
	cout << fractionToDecimal(100, -33) << endl;
	cout << fractionToDecimal(-1, -2147483648) << endl;

	for (int i = 1; i < 10; i++)
		cout << fractionToDecimal(1, pow(2, i)-1) << endl;

	return 0;
}
