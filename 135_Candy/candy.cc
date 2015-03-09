/**********************************************************************

 There are N children standing in a line. Each child is assigned a rating value.

 You are giving candies to these children subjected to the following requirements:
 
 Each child must have at least one candy.
 Children with a higher rating get more candies than their neighbors.
 What is the minimum candies you must give?

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

static inline int getMax(int a, int b) {
	return (a > b ? a : b);
}

int candy(vector<int> &ratings) {
	int sum, beginIdx, endIdx, lowValueIdx;
	vector<int> candies = vector<int>(ratings.size(), 0);

	for (int i = 0; i < ratings.size(); i++) {
		if (i == 0) {
			beginIdx = 0;
			lowValueIdx = 0;
			while (++i < ratings.size() && ratings[i] > ratings[i-1])
				;
			endIdx = --i;
		} else {
			beginIdx = endIdx;
			if (ratings[i] == ratings[i-1])
				beginIdx++;
			while (++i < ratings.size() && ratings[i] < ratings[i-1])
				;
			lowValueIdx = --i;
			while (++i < ratings.size() && ratings[i] > ratings[i-1])
				;
			endIdx = --i;
		}
		for (int j = beginIdx; j <= lowValueIdx; j++)
			candies[j] = getMax(candies[j], lowValueIdx-j+1);
		for (int j = lowValueIdx+1; j <= endIdx; j++)
			candies[j] = getMax(candies[j], j-lowValueIdx+1);
	}

	sum = 0;
	for (int i = 0; i < candies.size(); i++) {
		sum += candies[i];
	}

	return sum;
}

int main(int argc, char *argv[])
{
	int array1[] = {10,10,9,9,7,7,8,8,6,6};
	int array2[] = {1,1,2,2,2};
	int array3[] = {1,1,1,1,1};
	int array4[] = {1,10,9,4,5,7,8,2,3};
	vector<int> rating1, rating2, rating3, rating4;

	rating1 = vector<int>(array1, array1+sizeof(array1)/sizeof(int));
	cout << candy(rating1) << endl;
	rating2 = vector<int>(array2, array2+sizeof(array2)/sizeof(int));
	cout << candy(rating2) << endl;
	rating3 = vector<int>(array3, array3+sizeof(array3)/sizeof(int));
	cout << candy(rating3) << endl;
	rating4 = vector<int>(array4, array4+sizeof(array4)/sizeof(int));
	cout << candy(rating4) << endl;

	return 0;
}
