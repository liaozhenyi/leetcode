/**********************************************************************

 Given an array of integers, every element appears twice except for one. 
 Find that single one.

 Note:
 Your algorithm should have a linear runtime complexity. Could you implement 
 it without using extra memory?

**********************************************************************/

#include <iostream>
#include <cassert>
#include <cstring>

/* 
 * Method One: using XOR operator 
 *
int singleNumber(int A[], int n) {
	int ans = 0;

	for (int i = 0; i < n; i++)
		ans ^= A[i];

	return ans;
}
 */

int main(int argc, char *argv[])
{
	int arr1[] = {-5};
	int arr2[] = {-5,0,-5};

	std::cout << singleNumber(arr1, sizeof(arr1)/sizeof(int)) << std::endl;
	std::cout << singleNumber(arr2, sizeof(arr2)/sizeof(int)) << std::endl;

	return 0;
}
