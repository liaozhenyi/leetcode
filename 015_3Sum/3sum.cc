/**********************************************************************

 Given an array S of n integers, are there elements a, b, c in S such 
 that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

 Note:
 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 The solution set must not contain duplicate triplets.
     For example, given array S = {-1 0 1 2 -1 -4},
 
     A solution set is:
     (-1, 0, 1)
     (-1, -1, 2)

***********************************************************************/

struct Interval {
	int low;
	int high;
};

vector<vector<int> > threeSum(vector<int> &nums) {
	vector<vector<int>> ans;

	std::sort(nums.begin(), nums.end());
	std::map<int, struct Interval> hashTable;

	for (int i = 0; i < nums.size(); ++i) {
		auto it = hashTable.find(nums[i]);
		if (it != hashTable.end()) {
			it->second.high = i;
		} else {
			struct Interval tmp = {i, i};
			hashTable.insert(std::pair<int, struct Interval>(nums[i], tmp));
		}
	}

	for (int i = 0; i+2 < nums.size(); ++i) {
		if (i > 0 && nums[i] == nums[i-1])
			continue;
		for (int j = i+1; j+1 < nums.size(); ++j) {
			if (j > i+1 && nums[j] == nums[j-1])
				continue;
			
			int cur1 = nums[i], cur2 = nums[j];
			int needed = -cur1-cur2;
			auto it = hashTable.find(needed);

			if (it != hashTable.end()) {
				if (it->second.high > j) {	
					vector<int> cases;
					cases.push_back(cur1);
					cases.push_back(cur2);
					cases.push_back(needed);
					ans.push_back(cases);
				}
			}
		}
	}

	return ans;
}
