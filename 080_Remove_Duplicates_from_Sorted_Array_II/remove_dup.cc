/**********************************************************************

 Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?
 
 For example,
 Given sorted array A = [1,1,1,2,2,3],
 
 Your function should return length = 5, and A is now [1,1,2,2,3].

**********************************************************************/

/*
 * use cnt to record how many dup of A[idx] had stored
 */
int removeDuplicates(int A[], int n) {
	int idx = -1;
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (idx < 0) {
			A[++idx] = A[i];
			count = 1;
		} else if (A[i] != A[idx]) {
			A[++idx] = A[i];
			count = 1;
		} else {
			if (count < 2) {
				A[++idx] = A[i];
				++count;
			}
		}
	}
	return idx+1;
}
