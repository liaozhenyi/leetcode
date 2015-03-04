/**********************************************************************

 he demons had captured the princess (P) and imprisoned her in the bottom-right 
 corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid.
 Our valiant knight (K) was initially positioned in the top-left room and must 
 fight his way through the dungeon to rescue the princess.

 The knight has an initial health point represented by a positive integer. 
 If at any point his health point drops to 0 or below, he dies immediately.
 
 Some of the rooms are guarded by demons, so the knight loses health (negative 
 integers) upon entering these rooms; other rooms are either empty (0's) or 
 contain magic orbs that increase the knight's health (positive integers).
 
 In order to reach the princess as quickly as possible, the knight decides 
 to move only rightward or downward in each step.
 
 
 Write a function to determine the knight's minimum initial health so that 
 he is able to rescue the princess.
 
 For example, given the dungeon below, the initial health of the knight must 
 be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
 
 -2 (K)	-3	3
 -5	-10	1
 10	30	-5 (P)
 
 Notes:
 
 The knight's health has no upper bound.
 Any room can contain threats or power-ups, even the first room the knight 
 enters and the bottom-right room where the princess is imprisoned.

**********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

const int ARRAYSIZE = 1000;

inline int getMin(int a, int b)
{
	return (a > b ? b : a);
}

int calculateMinimumHP(vector<vector<int> > &dungeon) {
	int minHPNeeded;
	int length, width;
	int minHP[ARRAYSIZE] = {0};

	if (!(length = dungeon.size()) || !(width = dungeon[0].size()))
		return 0;

	minHP[width-1] = 1;
	for (int i = length-1; i >= 0; i--)
		for (int j = width-1; j >= 0; j--) {
			if (j == width-1)
				minHPNeeded = minHP[j];
			else if (i == length-1)
				minHPNeeded = minHP[j+1];
			else
				minHPNeeded = getMin(minHP[j], minHP[j+1]);
			if (dungeon[i][j] < minHPNeeded)
				minHP[j] = minHPNeeded - dungeon[i][j];
			else
				minHP[j] = 1;
		}
	return minHP[0];
}

int main(int argc, char *argv[])
{
	int array1[] = {-2,-3,3,-5,-10,1,10,30,-5};
	int array2[] = {1,2,3,4};
	int array3[] = {-20};
	vector<vector<int> > dungeon1, dungeon2, dungeon3;

	dungeon1.push_back(vector<int>(array1, array1+3));
	dungeon1.push_back(vector<int>(array1+3, array1+6));
	dungeon1.push_back(vector<int>(array1+6, array1+9));

	dungeon2.push_back(vector<int>(array2, array2+2));
	dungeon2.push_back(vector<int>(array2+2, array2+4));

	dungeon3.push_back(vector<int>(array3, array3+1));

	cout << calculateMinimumHP(dungeon1) << endl;
	cout << calculateMinimumHP(dungeon2) << endl;
	cout << calculateMinimumHP(dungeon3) << endl;



	return 0;
}
