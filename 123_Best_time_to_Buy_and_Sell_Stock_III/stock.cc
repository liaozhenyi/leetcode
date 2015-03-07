/**********************************************************************

 Say you have an array for which the ith element is the price of a given 
 stock on day i.

 Design an algorithm to find the maximum profit. You may complete at most 
 two transactions.
 
 Note:
 You may not engage in multiple transactions at the same time (ie, you must 
 sell the stock before you buy again).

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int profit(vector<int> pricesFloat)
{
	int ret;
	vector<int>::iterator it;
	vector<int> sumProfit;

	ret = 0;
	if (!pricesFloat.size())
		return 0;

	for (it = pricesFloat.begin(); it != pricesFloat.end(); it++) {
		if (it == pricesFloat.begin())
			sumProfit.push_back(*it);
		else if (*sumProfit.rbegin() < 0)
			sumProfit.push_back(*it);
		else
			sumProfit.push_back(*it+*sumProfit.rbegin());
	}
	for (it = sumProfit.begin(); it != sumProfit.end(); it++)
		if (*it > ret)
			ret = *it;

	return ret;
}

int maxProfit(vector<int> &prices) {
	int ans, sum;
	int maxLeftProfit, maxRightProfit;
	vector<int>::iterator it;
	vector<int> pricesFloat, optimizePricesFloat;

	sum = 0;

	for (it = prices.begin(); it!= prices.end() && it+1 != prices.end(); it++)
		pricesFloat.push_back(*(it+1)-*it);
	for (it = pricesFloat.begin(); it != pricesFloat.end(); it++) {
		int subSum = *it;
		while (++it != pricesFloat.end() && (
			subSum*(*it) >= 0))
			subSum += (*it);
		--it;
		sum += subSum;
		optimizePricesFloat.push_back(subSum);
	}

	ans = (sum > 0 ? sum : 0);
		
	for (it = optimizePricesFloat.begin(); it != optimizePricesFloat.end(); it++) {
		if (*it >= 0)
			continue;
		maxLeftProfit = profit(vector<int>(optimizePricesFloat.begin(), it));
		maxRightProfit = profit(vector<int>(it+1, optimizePricesFloat.end()));
		if (maxLeftProfit+maxRightProfit > ans)
			ans = maxLeftProfit+maxRightProfit;	
	}
	return ans;
}

int main(int argc, char *argv[])
{
	int array1[] = {1,2,3,4,5,6,7,8,9,10};
	int array2[] = {10,9,8,7,2,3,4,5,6,1};
	int array3[] = {1,2,7,3,4,5,10,7,8,9};
	int array4[] = {};
	vector<int> price1 = vector<int>(array1, array1+sizeof(array1)/sizeof(int));
	vector<int> price2 = vector<int>(array2, array2+sizeof(array2)/sizeof(int));
	vector<int> price3 = vector<int>(array3, array3+sizeof(array3)/sizeof(int));
	vector<int> price4 = vector<int>(array4, array4+sizeof(array4)/sizeof(int));

	cout << maxProfit(price1) << endl;
	cout << maxProfit(price2) << endl;
	cout << maxProfit(price3) << endl;
	cout << maxProfit(price4) << endl;

	return 0;
}
