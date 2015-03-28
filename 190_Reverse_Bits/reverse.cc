/**********************************************************************

 Reverse bits of a given 32 bits unsigned integer.

 For example, given input 
 43261596 (represented in binary as 00000010100101000001111010011100), 
 return 964176192 (represented in binary as 00111001011110000010100101000000).
 
 Follow up:
 If this function is called many times, how would you optimize it?

**********************************************************************/


uint32_t reverseBits(uint32_t n) {
	uint32_t ans = 0;

	for (int i = 1; i < 32; i++) {
		ans = (ans + (n & 1)) << 1;
		n = n >> 1;
	}
	ans += n & 1;

	return ans;
}
