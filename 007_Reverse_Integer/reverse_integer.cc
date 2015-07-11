/**********************************************************************

  Reverse digits of an integer.

  Example1: x = 123, return 321
  Example2: x = -123, return -321

***********************************************************************/

// reverse(x) may overflow
int reverse(int x) {
	bool sign;
	long long num;

	if (x < 0) {
		num = (long long)0-x;
		sign = false;
	} else {
		num = x;
		sign = true;
	}

	int ans = 0;
	while (num) {
		int a = num%10;
		num /= 10;
		if (ans > (INT_MAX-a)/10)
			return 0;
		ans = ans*10 + a;
	}
	return sign ? ans : -ans;
}
