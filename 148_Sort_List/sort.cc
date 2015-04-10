/**********************************************************************

 Sort a linked list in O(n log n) time using constant space complexity.

**********************************************************************/

ListNode *mergeList(ListNode *h1, ListNode *h2, ListNode *next) {
	ListNode *head = NULL, *tail, *cur1 = h1, *cur2 = h2;

	assert (NULL != h1 && NULL != h2);

	while (cur1 != h2 && cur2 != next) {
		if (cur1->val < cur2->val) {
			if (NULL == head) {
				head = cur1;
				tail = head;
			} else {
				tail->next = cur1;
				tail = cur1;
			}
			cur1 = cur1->next;
		} else {
			if (NULL == head) {
				head = cur2;
				tail = cur2;
			} else {
				tail->next = cur2;
				tail = cur2;
			}
			cur2 = cur2->next;
		}
	}
	while (cur1 != h2) {
		tail->next = cur1;
		tail = cur1;
		cur1 = cur1->next;
	}
	while (cur2 != next) {
		tail->next = cur2;
		tail = cur2;
		cur2 = cur2->next;
	}
	tail->next = next;
	return head;
}

ListNode *sortList(ListNode *head) {
	ListNode *pre, *head1, *tail1, *head2, *tail2, *next;
	int listSize, mergeSize;

	listSize = 0;
	mergeSize = 1;
	for (head1 = head; head1 != NULL; head1 = head1->next)
		++listSize;

	while (mergeSize < listSize) {
		pre = NULL;
		for (head1 = head; head1 != NULL; ) {
			tail1 = head1;
			for (int i = 1; i < mergeSize; i++) {
				if (NULL == tail1->next)
					break;
				tail1 = tail1->next;
			}
			head2 = tail1->next;
			if (NULL == head2)
				break;
			tail2 = head2;
			for (int i = 1; i < mergeSize; i++) {
				if (NULL == tail2->next)
					break;
				tail2 = tail2->next;
			}
			next = tail2->next;
			if (NULL == pre)
				head = mergeList(head1, head2, next);
			else
				pre->next = mergeList(head1, head2, next);
				
			pre = tail1->val > tail2->val ? tail1 : tail2;
			// if tail1 equals to tail2, pre may not point to the right position!
			while (pre->next != next)
			    pre = pre->next;
			head1 = next;
		}
		mergeSize *= 2;
	}

	return head;
}
