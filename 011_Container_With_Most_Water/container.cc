/**********************************************************************

 Given n non-negative integers a1, a2, ..., an, where each represents a 
 point at coordinate (i, ai). n vertical lines are drawn such that the 
 two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which 
 together with x-axis forms a container, such that the container contains 
 the most water.

 Note: You may not slant the container.

***********************************************************************/

static inline int getMin(int a, int b) {
	return a > b ? b : a;
}

int maxArea(vector<int> &height)
{
	int low, high;
	int maxA;

	low = 0;
	high = height.size()-1;
	maxA = 0;

	while (low < high) {
		int minH = getMin(height[low], height[high]);
		if (minH*(high-low) > maxA)
			maxA = minH*(high-low);

		if (height[low] < height[high])
			++low;
		else
			--high;
	}

	return maxA;
}
