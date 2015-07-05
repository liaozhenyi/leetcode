/**********************************************************************

 Given an array of integers, find two numbers such that they add up to a 
 specific target number.

 The function twoSum should return indices of the two numbers such that 
 they add up to the target, where index1 must be less than index2. Please 
 note that your returned answers (both index1 and index2) are not zero-based.
 
 You may assume that each input would have exactly one solution.
 
 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2

**********************************************************************/


typedef struct node {
	int val;
	struct node *next;
} Node;

inline int getHash(int num, int hashSize) {
	if (num >= 0) {
		return num%hashSize;
	} else if (num == INT_MIN) {
		return hashSize-(-(num+hashSize))%hashSize;
	} else {
		return hashSize-(-num)%hashSize;
	}
}

void freeNode(Node **hash, int hashSize) {
	for (int i = 0; i < hashSize; i++) {
		Node *cur = hash[i];
		while (cur) {
			Node *tmp = cur;	
			cur = cur->next;
			delete tmp;
		}
	}
	delete []hash;
}

vector<int> findValue(vector<int> &numbers, int value1, int value2) {
	vector<int> ans;
	vector<int>::const_iterator it;

	for (it = numbers.begin(); it != numbers.end(); it++) {
		if (*it == value1 && !ans.size()) {
			ans.push_back(it-numbers.begin()+1);
		} else if (*it == value2) {
			ans.push_back(it-numbers.begin()+1);
			break;
		}
	}
	if (!ans.size())
		ans = vector<int>(2, -1);
	return ans;
}

/* The size of numbers can't be too big */
vector<int> twoSum(vector<int> &numbers, int target) {
	int hashSize, targetIdx;
	int value1, value2;
	Node **hash;

	value1 = INT_MIN;
	value2 = INT_MIN;
	hashSize = numbers.size();
	hash = new Node *[hashSize];
	memset(hash, 0, hashSize*sizeof(Node *));
	targetIdx = getHash(target, hashSize);

	for (int i = 0; i < numbers.size(); i++) {
		int idx = getHash(numbers[i], hashSize);
		int counterIdx = getHash(targetIdx-idx, hashSize);
		Node *cur = hash[counterIdx];
		while (cur) {
			if (cur->val + numbers[i] == target) {
				value1 = cur->val;
				value2 = numbers[i];
				break;
			}
			cur = cur->next;
		}
		if (value1 != INT_MIN || value2 != INT_MIN)
			break;

		Node *newNode = new Node;
		newNode->val = numbers[i];
		newNode->next = hash[idx];
		hash[idx] = newNode;
	}

	freeNode(hash, hashSize);
	return findValue(numbers, value1, value2);
}

/* 2nd round @ 07.05 */

int num2idx(int num, int size) {
	if (num >= 0)
		return num%size;
	else if (num == INT_MIN)
		return size -1 - (-1-num)%size;
	else
		return size - (-num)%size;
	
}

vector<int> twoSum(vector<int> &nums, int target) {
	int size = nums.size();
	int num1, num2;
	int targetIdx = num2idx(target, size);

	vector<vector<int> > hashTable(size, vector<int>(0));
	for (auto n: nums) {
		int idx = num2idx(n, size);
		int counterIdx = num2idx(targetIdx-idx, size);
		for (auto m: hashTable[counterIdx]) 
			if (m+n == target) {
				num1 = m;
				num2 = n;
				goto found;
			}
		hashTable[idx].push_back(n);
	}

found:
	vector<int> ans;
	for (int idx = 0; idx < size; ++idx) {
		if (nums[idx] == num1) {
			ans.push_back(idx+1);
		} else if (nums[idx] == num2) {
			ans.push_back(idx+1);
			return ans;
		}
	}
}

