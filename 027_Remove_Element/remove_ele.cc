/**********************************************************************

 Given an array and a value, remove all instances of that value in place 
 and return the new length.

 The order of elements can be changed. It doesn't matter what you leave 
 beyond the new length.

**********************************************************************/

/*
 * Use a idx+1 to record the next position to insert into
 */
int removeElement(int A[], int n, int elem) {
	int idx = -1;
	
	for (int i = 0; i < n; i++) {
		if (elem != A[i]) {
			A[++idx] = A[i];
		}
	}
	return idx+1;
}
