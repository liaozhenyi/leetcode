/**********************************************************************

 Say you have an array for which the ith element is the price of a given 
 stock on day i.

 Design an algorithm to find the maximum profit. You may complete at most 
 k transactions.
 
 Note:
 You may not engage in multiple transactions at the same time (ie, you must 
 sell the stock before you buy again).

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int k, vector<int> &prices) {
	int ans;
	vector<int> pricesFloat, optimizePricesFloat;
	// profit[i][j]: within day(1, i+1) and j transactions
	vector<vector<int> > profit; 
	// sumProfit[j] from day (i) to j+1, 1 transaction
	vector<int> sumProfit; 
	
	ans = 0;
	if (k <= 0 || prices.size() <= 1)
		return 0;
	
	for (int i = 1; i < prices.size(); i++)
		pricesFloat.push_back(prices[i]-prices[i-1]);
	for (int i = 0; i < pricesFloat.size(); i++) {
		int price = pricesFloat[i];
		while (++i < pricesFloat.size() && (
			price * pricesFloat[i] >= 0))
			price += pricesFloat[i];
		i--;
		optimizePricesFloat.push_back(price);
	}
	/* holy shit, get a "Memory Limit Exceed" ERROR!
	for (int i = 0; i < pricesFloat.size(); i++) {
		sumProfit.push_back(vector<int>(pricesFloat.size(), 0));
		for (int j = i; j < pricesFloat.size(); j++) {
			int max = 0;
			if (i == j) {
				max = (max > pricesFloat[j] ? max : pricesFloat[j]);
			} else {
				if((sumProfit[i][j-1]+pricesFloat[j]) > 0)
					max = pricesFloat[j]+sumProfit[i][j-1];
			}
			sumProfit[i][j] = max;
		}
	}
	*/

	// Without this optimize, for big k and array, I still couldn't pass
	// the test case, like k=100000000, array with has about 10000 elements
	if (k >= optimizePricesFloat.size()) {
		for (int i = 0; i < optimizePricesFloat.size(); i++) {
			if (optimizePricesFloat[i] > 0)
				ans += optimizePricesFloat[i];
		}
		return ans;
	}

	for (int i = 0; i < optimizePricesFloat.size(); i++) {
		sumProfit.erase(sumProfit.begin(), sumProfit.end());
		sumProfit = vector<int>(i+1, 0);
		for (int j = i; j >= 0; j--) {
			int max = 0;
			if (i == j) {
				max = (max > optimizePricesFloat[j] ? max : optimizePricesFloat[j]);
			} else {
				if (sumProfit[j+1]+optimizePricesFloat[j] > 0)
					max = sumProfit[j+1]+optimizePricesFloat[j];
			}
			sumProfit[j] = max;
		}

		profit.push_back(vector<int>());
		for (int round = 0; round < k; round++) {
			int max = sumProfit[0];
			for (int j = 1; j < i; j++)
				if (max < sumProfit[j])
					max = sumProfit[j];
			profit[i].push_back(max);
			if (!round)
				continue;
			for (int j = 0; j < i; j++) {
				int sum = profit[j][round-1]+sumProfit[j+1];
				if (profit[i][round] < sum)
					profit[i][round] = sum;
			}
		}
	}
	/*
	 * O(k*n^3) time complexity, you must be kidding!
	for (int round = 1; round <= k; round++) {
		for (int i = 0; i < pricesFloat.size(); i++) {
			for (int j = pricesFloat.size()-1; j >= i; j--) {
				profit[i][j] = sumProfit[i][j];
				for (int l = i; l < j; l++) {
					int sum = profit[i][l] + sumProfit[l+1][j];
					if (profit[i][j] < sum)
						profit[i][j] = sum;
				}

			}
		}
	}
	*/

	for (int i = 0; i < optimizePricesFloat.size(); i++) {
		for (int j = 0; j < k; j++) {
			if (ans < profit[i][j])
				ans = profit[i][j];
		}
	}

	return ans;
}

int main(int argc, char *argv[])
{
	int array1[] = {1,2,3,4,5,6,7,8,9,10};
	int array2[] = {10,9,8,7,2,3,4,5,6,1};
	int array3[] = {1,2,7,3,4,5,10,7,8,9};
	vector<int> price1 = vector<int>(array1, array1+sizeof(array1)/sizeof(int));
	vector<int> price2 = vector<int>(array2, array2+sizeof(array2)/sizeof(int));
	vector<int> price3 = vector<int>(array3, array3+sizeof(array3)/sizeof(int));

	cout << maxProfit(1, price1) << endl;
	cout << maxProfit(1, price2) << endl;
	cout << maxProfit(1, price3) << endl;
	cout << maxProfit(2, price3) << endl;
	cout << maxProfit(3, price3) << endl;

	return 0;
}
