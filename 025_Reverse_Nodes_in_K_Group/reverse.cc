/**********************************************************************

 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 
 You may not alter the values in the nodes, only nodes itself may be changed.
 
 Only constant memory is allowed.
 
 For example,
 Given this linked list: 1->2->3->4->5
 
 For k = 2, you should return: 2->1->4->3->5
 
 For k = 3, you should return: 3->2->1->4->5

***********************************************************************/

ListNode *reverseList(ListNode *head, ListNode *tail) {
	if (NULL == head || head == tail)
		return head;
	ListNode *newHead = head, *cur = head->next;

	while (1) {
		ListNode *tmp = cur;
		cur = cur->next;
		tmp->next = newHead;
		newHead = tmp;
		if (tmp == tail)
			break;
	}

	return newHead;
}

ListNode *reverseKGroup(ListNode *head, int k) {
	ListNode *phead = new ListNode(0);
	ListNode *prev, *next, *currhead, *currtail;

	phead->next = head;
	currhead = head;
	prev = phead;
	while (currhead) {
		currtail = currhead;
		for (int i = 1; i < k; ++i) {
			currtail = currtail->next;
			if (NULL == currtail)
				goto ret;
		}
		next = currtail->next;

		prev->next = reverseList(currhead, currtail);
		currhead->next = next;

		prev = currhead;
		currhead = next;
	}
ret:
	return phead->next;
}
