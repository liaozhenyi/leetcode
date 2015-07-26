/**********************************************************************

 Merge two sorted linked lists and return it as a new list. The new list 
 should be made by splicing together the nodes of the first two lists.

***********************************************************************/

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	ListNode head = ListNode(0);
	ListNode *tail = &head, *tmp;

	while (l1 && l2) {
		if (l1->val < l2->val) {
			tmp = l1;
			l1 = l1->next;
		} else {
			tmp = l2;
			l2 = l2->next;
		}

		tmp->next = tail->next;
		tail->next = tmp;
		tail = tmp;
	}

	if (l1)
		tail->next = l1;
	if (l2)
		tail->next = l2;

	return head.next;
}
