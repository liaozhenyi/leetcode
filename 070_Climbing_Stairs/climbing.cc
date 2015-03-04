/**********************************************************************

 You are climbing a stair case. It takes n steps to reach to the top.

 Each time you can either climb 1 or 2 steps. In how many distinct ways 
 can you climb to the top?

**********************************************************************/

#include <iostream>

using namespace std;

int climbStairs(int n) {
	int ans;
	int *ways = new int[n+1];

	for (int i = 0; i <= n; i++) {
		if (i < 2)
			ways[i] = 1;
		else
			ways[i] = ways[i-1]+ways[i-2];
	}

	ans = ways[n];
	delete []ways;
	return ans;
}

int main(int argc, char *argv[])
{
	for (int i = 0; i < 10; i++)
		cout << climbStairs(i) << endl;

	return 0;
}
