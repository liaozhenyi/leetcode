/**********************************************************************

 You are given two linked lists representing two non-negative numbers. 
 The digits are stored in reverse order and each of their nodes contain 
 a single digit. Add the two numbers and return it as a linked list.

 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8

***********************************************************************/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode *lsum = NULL, *lsumtail = NULL;
	ListNode *cur1 = l1, *cur2 = l2;
	bool carry = 0;

	while (cur1 || cur2 || carry) {
		int num = carry;
		if (cur1) {
			num += cur1->val;
			cur1 = cur1->next;
		}
		if (cur2) {
			num += cur2->val;
			cur2 = cur2->next;
		}

		carry = num / 10;
		num %= 10;
		ListNode *node = new ListNode(num);

		if (NULL == lsum) {
			lsum = node;
			lsumtail = node;
		} else {
			lsumtail->next = node;
			lsumtail = node;
		}
	}

	return lsum;
}
