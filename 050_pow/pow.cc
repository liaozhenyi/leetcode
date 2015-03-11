/**********************************************************************

 Implement pow(x,n).

**********************************************************************/

#include <iostream>

double pow(double x, int n) {
	bool nNegative;
	long nValue;
	double multiplicator, ans;

	nValue = n;
	if (nValue >= 0) {
		nNegative = false;
	} else {
		nNegative = true;
		nValue = -nValue;
	}

	multiplicator = x;
	ans = 1.0;
	while (nValue) {
		if (nValue & 1)
			ans *= multiplicator;
		multiplicator *= multiplicator;
		nValue = nValue>>1;
	}
	if (nNegative)
		ans = 1.0/ans;

	return ans;
}

int main(int argc, char *argv[])
{
	for (int i = -3; i < 10; i++)
		std::cout << pow(1.5, i) << std::endl;
	std::cout << pow(1.0, -2147483648);

	return 0;
}
