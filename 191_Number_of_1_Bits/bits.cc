/**********************************************************************

 Write a function that takes an unsigned integer and returns the number 
 of ’1' bits it has (also known as the Hamming weight).

 For example, the 32-bit integer ’11' has binary representation 
 00000000000000000000000000001011, so the function should return 3.

**********************************************************************/

/*
 * Method One: Shifting one bit each time
 */
int hammingWeight(uint32_t n) {
	int ans = 0;

	while (n) {
		ans += n & 1;
		n = n >> 1;
	}

	return ans;
}

/*
 * Method Two: Reset the lowest one to zero each time,
 * implement by a &= (a-1) while a != 0, like:
 * 01101000  -> 01101000 & 01100111 = o1100000
 */
int hammingWeight(uint32_t n) {
	int ans = 0;

	while (n) {
		++ans;
		n &= (n-1);
	}

	return ans;
}
