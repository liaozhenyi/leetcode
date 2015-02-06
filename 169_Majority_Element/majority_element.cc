/**********************************************************************

 Given an array of size n, find the majority element. The majority element 
 is the element that appears more than ⌊ n/2 ⌋ times.

 You may assume that the array is non-empty and the majority element always 
 exist in the array.

**********************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int majorityElement(vector<int> &num) {
	int count, major;
	vector<int>::iterator iter;

	count = 0;
	major = 0;

	for (iter = num.begin(); iter != num.end(); iter++) {
		if (!count) {
			major = *iter;
			count++;
		} else {
			if (*iter == major)
				count++;
			else
				count--;
		}
	}

	// If the majority element not always exist, we need to
	// do a final check.
	count = 0;
	for(iter = num.begin(); iter != num.end(); iter++)
		if (*iter == major)
			count++;
		else
			count--;
	major = count>0 ? major : 0;

	return major;
}

int main(int argc, char *argv[])
{
	srand((unsigned)time(0));
	vector<int> num;

	for (int i = 0; i < 50; i++) {
		num.push_back(rand()%1000);
		num.push_back(23);
	}
	num.push_back(23);

	cout << majorityElement(num) << endl;
}
