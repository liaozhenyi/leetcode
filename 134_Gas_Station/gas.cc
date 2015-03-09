/**********************************************************************

 There are N gas stations along a circular route, where the amount of gas 
 at station i is gas[i].

 You have a car with an unlimited gas tank and it costs cost[i] of gas to 
 travel from station i to its next station (i+1). You begin the journey 
 with an empty tank at one of the gas stations.
 
 Return the starting gas station's index if you can travel around the 
 circuit once, otherwise return -1.
 
 Note:
 The solution is guaranteed to be unique.

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	int gasSum, minGas, pos;
	vector<int> gasLeft;

	pos = -1;
	gasSum = 0;

	for (int i = 0; i < gas.size(); i++)
		gasLeft.push_back(gas[i]-cost[i]);

	for (int i = 0; i < gasLeft.size(); i++) {
		if (gasLeft[i] >= 0 && pos == -1) {
			minGas = gasSum;
			pos = i;
		}
		gasSum += gasLeft[i];
		if (gasSum < minGas) {
			pos = -1;
			minGas = gasSum;
		}
	}

	if (gasSum >= 0)
		return pos;
	return -1;
}

int main(int argc, char *argv[]) {
	int array1[] = {1,2,3,4,5};
	int array2[] = {3,4,5,1,2};
	int array3[] = {};
	int array4[] = {6,1,4,3,5};
	int array5[] = {3,8,2,4,2};
	vector<int> gas1, cost1;

	gas1 = vector<int>(array1, array1+sizeof(array1)/sizeof(int));
	cost1 = vector<int>(array2, array2+sizeof(array2)/sizeof(int));
	cout << canCompleteCircuit(gas1, cost1) << endl;

	gas1 = vector<int>(array3, array3+sizeof(array3)/sizeof(int));
	cost1 = vector<int>(array3, array3+sizeof(array3)/sizeof(int));
	cout << canCompleteCircuit(gas1, cost1) << endl;


	gas1 = vector<int>(array4, array4+sizeof(array4)/sizeof(int));
	cost1 = vector<int>(array5, array5+sizeof(array5)/sizeof(int));
	cout << canCompleteCircuit(gas1, cost1) << endl;


	return 0;
}
