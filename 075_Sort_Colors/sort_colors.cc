/**********************************************************************

 Given an array with n objects colored red, white or blue, sort them so 
 that objects of the same color are adjacent, with the colors in the order 
 red, white and blue.

 Here, we will use the integers 0, 1, and 2 to represent the color red, 
 white, and blue respectively.

**********************************************************************/

/*
 * The array only contain constant kinds of number, 
 * using count sort.
 */
void sortColors(int A[], int n) {
	int count[3] = {0};

	for (int i = 0; i < n; i++) {
		++count[A[i]];
	}
	int idx = -1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < count[i]; j++)
			A[++idx] = i;
	}
}
