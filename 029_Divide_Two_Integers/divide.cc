/**********************************************************************

 Divide two integers without using multiplication, division and mod operator.

 If it is overflow, return MAX_INT.

**********************************************************************/

#include <iostream>
#include <climits>

/* Two cases will case the division overflow:
 * 1. dividend = 0
 * 2. dividend = -1 && divisor = INT_MIN
 * Be careful when divisor = INT_MIN and dividend = 1
 */
int divide(int dividend, int divisor) {
	int sign, quotient;
	long longDividend, longDivisor;
	long factor;

	if (!dividsor || (dividsor == -1 && dividend == INT_MIN))
		return INT_MAX;

	quotient = 0;
	sign = 1;
	factor = 1;
	if (dividend < 0) {
		sign *= -1;
		longDividend = (long)0-dividend;
	} else {
		longDividend = dividend;
	}
	if (divisor < 0) {
		sign *= -1;
		longDivisor = (long)0-divisor;
	} else {
		longDivisor = divisor;
	}
	
	while (longDivisor*factor < longDividend) {
		factor *= 2;
	}
	while (factor) {
		if (longDividend >= factor*longDivisor) {
			quotient += factor*sign;
			longDividend -= factor*longDivisor;
		}
		factor/=2;
	}

	return quotient;
}

int main(int argc, char *argv[])
{
	std::cout << divide(INT_MAX, 1) << std::endl;
	std::cout << divide(1, INT_MIN) << std::endl;
	std::cout << divide(INT_MIN, 2) << std::endl;
	std::cout << divide(INT_MIN, -3) << std::endl;
	std::cout << divide(87, 3) << std::endl;
	std::cout << divide(-3, 5) << std::endl;
	std::cout << divide(5, -3) << std::endl;
	
	return 0;
}
