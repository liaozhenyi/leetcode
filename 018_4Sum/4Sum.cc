/**********************************************************************

  Given an array S of n integers, are there elements a, b, c, and d in S 
  such that a + b + c + d = target? Find all unique quadruplets in the array 
  which gives the sum of target.

 Note:
 Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 The solution set must not contain duplicate quadruplets.
     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 
     A solution set is:
     (-1,  0, 0, 1)
     (-2, -1, 1, 2)
     (-2,  0, 0, 2)
 
***********************************************************************/

struct TwoNum {
	int num1, num2;
	int idx1, idx2;
	TwoNum *next;
	TwoNum(int n1, int n2, int i1, int i2): num1(n1), num2(n2), idx1(i1), idx2(i2), next(NULL) {};
};

int num2idx(int num, int size) {
	if (num >= 0)
		return num%size;
	else if (num == INT_MIN)
		return size-1 - (-1-num)%size;
	else
		return size - (-num)%size;
}

vector<vector<int> > fourSum(vector<int> &nums, int target) {
	vector<vector<int> > ans;
	int hSize = nums.size()+1;
	vector<TwoNum> hash(hSize, TwoNum(0, 0, 0, 0));
	std::sort(nums.begin(), nums.end());
	int targetIdx = num2idx(target, hSize);

	for (int i = 0; i < nums.size(); ++i) {
		for (int j = i+1; j < nums.size(); ++j) {
			int num1 = nums[i], num2 = nums[j];
			TwoNum *tnode = new TwoNum(num1, num2, i, j);	
			int idx = num2idx(num1+num2, hSize);
			int counterIdx = num2idx(targetIdx-idx, hSize);
			TwoNum *t = hash[counterIdx].next;
			int num3, num4;

			while (t) {
				if (t->idx2 >= i) {
					goto next;
				}

				num3 = t->num1;
				num4 = t->num2;

				if (num1+num2+num3+num4 == target) {
					vector<int> c;
					c.push_back(num3);
					c.push_back(num4);
					c.push_back(num1);
					c.push_back(num2);
					if (!ans.empty()) {
						for (auto &ac: ans)
							if (std::equal(c.begin(), c.end(), ac.begin())) {
								goto next;
							}
					}
					ans.push_back(c);
				}
next:
				t = t->next;
			}
			t = &hash[idx];
			tnode->next = t->next;
			t->next = tnode;
		}
	}

	return ans;
}
