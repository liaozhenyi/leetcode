/**********************************************************************

 Given an integer n, return the number of trailing zeroes in n!.

 Note: Your solution should be in logarithmic time complexity.

**********************************************************************/

int trailingZeroes(int n) {
	int ans = 0;

	assert(n >= 0);

	while (n) {
		n /= 5;
		ans += n;
	}

	return ans;
}
