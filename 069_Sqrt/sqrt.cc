/**********************************************************************

 Implement int sqrt(int x).

 Compute and return the square root of x.

**********************************************************************/

#include <iostream>

using namespace std;

int sqrt(int x) {
	int low, high, mid;

	low = 0;
	high = 2;
	while (x / high > high) {
		low = high;
		high *= 2;
	}
	while (low < high) {
		mid = (low+high)/2;
		if (mid == 0)
			return high;
		if (x / mid == mid) {
			return mid;
		} else if (x / mid < mid) {
			high = mid-1;
		} else {
			if (x / (mid+1) < (mid+1))
				high = mid;
			else if (x / (mid+1) == (mid+1))
				return mid+1;
			else
				low = mid + 1;
		}
	}

	return low;
}

int main(int argc, char *argv[])
{
	for (int i = 0; i <= 10; i++)
		cout << sqrt(i) << endl;
	cout << sqrt(65536) << endl;
	cout << sqrt(INT_MAX) << endl;

	return 0;
}
