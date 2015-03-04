/**********************************************************************

 Say you have an array for which the ith element is the price of a given 
 stock on day i.

 If you were only permitted to complete at most one transaction (ie, buy 
 one and sell one share of the stock), design an algorithm to find the 
 maximum profit.

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
	int ans;
	vector<int>::iterator it;
	vector<int> changes, profit;

	if (prices.size() < 2)
		return 0;

	for (it = prices.begin()+1; it != prices.end(); it++)
		changes.push_back(*it - *(it-1));
	for (it = changes.begin(); it != changes.end(); it++) {
		if (it == changes.begin()) {
			profit.push_back(*it);
		} else {
			if (*profit.rbegin() < 0)
				profit.push_back(*it);
			else
				profit.push_back(*it+*profit.rbegin());
		}
	}

	ans = 0;
	for (it = profit.begin(); it != profit.end(); it++)
		if (ans < *it)
			ans = *it;
	return ans;
}

int main(int argc, char *argv[])
{
	int array1[] = {1,2,3,4,5,6,7,8,9,10};
	int array2[] = {10,9,8,7,2,3,4,5,6,1};
	vector<int> price1 = vector<int>(array1, array1+sizeof(array1)/sizeof(int));
	vector<int> price2 = vector<int>(array2, array2+sizeof(array2)/sizeof(int));

	cout << maxProfit(price1) << endl;
	cout << maxProfit(price2) << endl;

	return 0;
}
