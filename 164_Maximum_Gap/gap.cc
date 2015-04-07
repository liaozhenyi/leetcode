/**********************************************************************

 Given an unsorted array, find the maximum difference between the successive 
 elements in its sorted form.

 Try to solve it in linear time/space.
 
 Return 0 if the array contains less than 2 elements.
 
 You may assume all elements in the array are non-negative integers and fit 
 in the 32-bit signed integer range.

**********************************************************************/

int maximumGap(vector<int> &num) {
	int maxGap = 0;
	sort(num.begin(), num.end());
	for (decltype(num.size()) i = 1; i < num.size(); i++) {
		if (maxGap < num[i]-num[i-1])
			maxGap = num[i]-num[i-1];
	}

	return maxGap;
}
