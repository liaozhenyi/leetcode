/**********************************************************************

 Implement next permutation, which rearranges numbers into the lexicographically 
 next greater permutation of numbers.

 If such arrangement is not possible, it must rearrange it as the lowest 
 possible order (ie, sorted in ascending order).
 
 The replacement must be in-place, do not allocate extra memory.
 
 Here are some examples. Inputs are in the left-hand column and its corresponding 
 outputs are in the right-hand column.
 1,2,3 → 1,3,2
 3,2,1 → 1,2,3
 1,1,5 → 1,5,1

**********************************************************************/

static inline void swap(int &a, int &b) {
	if (a == b)
		return ;
	a ^= b;
	b ^= a;
	a ^= b;
}

static void rotate(vector<int> &num, int low, int high) {
	while (low < high) {
		swap(num[low++], num[high--]);
	}
}

/*
 * find the idx that should be changed, and the swap idx'
 * like:
 *		9 6 5 8 7 2 1
 *		    ^   ^
 *		   idx idx'
 * if idx = -1, rotate the array
 */
void nextPermutation(vector<int> &num) {
	int idx, idx_;

	for (idx = num.size()-2; idx >= 0; idx--) {
		if (num[idx] < num[idx+1]) {
			for (idx_ = num.size()-1; idx_ > idx; idx_--)
				if (num[idx_] > num[idx])
					break;
			break;
		}
	}
	if (idx < 0) {
		rotate(num, 0, num.size()-1);
	} else {
		swap(num[idx], num[idx_]);
		rotate(num, idx+1, num.size()-1);
	}
}
