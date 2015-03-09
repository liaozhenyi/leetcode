/**********************************************************************

 Say you have an array for which the ith element is the price of a given 
 stock on day i.

 Design an algorithm to find the maximum profit. You may complete as many 
 transactions as you like (ie, buy one and sell one share of the stock multiple 
 times). However, you may not engage in multiple transactions at the same time 
 (ie, you must sell the stock before you buy again).

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
	int profit;
	vector<int>::iterator it;

	profit = 0;
	if (!prices.size())
		return profit;

	for (it = prices.begin()+1; it != prices.end(); it++) {
		if (*(it) > *(it-1))
			profit += *(it) - *(it-1);
	}

	return profit;
}

int main(int argc, char *argv[])
{
	int array1[] = {1,2,3,4,5,6,7,8,9,10};
	int array2[] = {10,9,8,7,2,3,4,5,6,1};
	int array3[] = {1,2,7,3,4,5,10,7,8,9};
	vector<int> price1 = vector<int>(array1, array1+sizeof(array1)/sizeof(int));
	vector<int> price2 = vector<int>(array2, array2+sizeof(array2)/sizeof(int));
	vector<int> price3 = vector<int>(array3, array3+sizeof(array3)/sizeof(int));

	cout << maxProfit(price1) << endl;
	cout << maxProfit(price2) << endl;
	cout << maxProfit(price3) << endl;

	return 0;
}
