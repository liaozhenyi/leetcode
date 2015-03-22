/**********************************************************************

 Given a sorted array, remove the duplicates in place such that each element 
 appear only once and return the new length.

 Do not allocate extra space for another array, you must do this in place 
 with constant memory.

 For example,
 Given input array A = [1,1,2],
 
 Your function should return length = 2, and A is now [1,2].

**********************************************************************/

/*
 * Use idx+1 to record the next position to insert into.
 */
int removeDuplicates(int A[], int n) {
	int idx = -1;

	for (int i = 0; i < n; i++) {
		if (idx < 0 || A[i] != A[idx]) {
			A[++idx] = A[i];
		}
	}
	return idx+1;
}
