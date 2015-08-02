/**********************************************************************

 Given a linked list, swap every two adjacent nodes and return its head.

 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.
 
 Your algorithm should use only constant space. You may not modify the values 
 in the list, only nodes itself can be changed.

***********************************************************************/

ListNode *swapPairs(ListNode *head) {
	if (NULL == head)
		return head;

	ListNode *prev, *next, *node1, *node2;
	ListNode phead;
	phead.next = head;

	prev = &phead;
	while (NULL != prev->next) {
		node1 = prev->next;
		if (NULL == node1->next)
			break;
		node2 = node1->next;
		next = node2->next;

		prev->next = node2;
		node2->next = node1;
		node1->next = next;

		prev = node1;
	}

	return phead.next;
}
