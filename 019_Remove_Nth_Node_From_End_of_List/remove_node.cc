/**********************************************************************

 Given a linked list, remove the nth node from the end of list and return its head.

 For example,
 
    Given linked list: 1->2->3->4->5, and n = 2.
 
    After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.

***********************************************************************/

int nodeCnt(ListNode *n) {
	int cnt = 0;

	while (n) {
		n = n->next;
		++cnt;
	}
	return cnt;
}

ListNode *removeNthFromEnd(ListNode * head, int n) {
	ListNode H = ListNode(0);
	int listSize;

	H.next = head;
	listSize = nodeCnt(head);

	if (n > listSize)
		return H.next;
	ListNode *cur = &H;
	for (int i = listSize; i > n; --i)
		cur = cur->next;
	cur->next = cur->next->next;

	return H.next;
}
