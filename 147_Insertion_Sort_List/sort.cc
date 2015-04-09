/**********************************************************************

 Sort a linked list using insertion sort.

**********************************************************************/

ListNode *insertionSortList(ListNode *head) {
	ListNode *head_;
	ListNode *pre, *tmp;

	while (head) {
		if (NULL == head_) {
			head_ = head;
			head = head->next;
			head_->next = NULL;
		} else {
			pre = NULL;
			tmp = head_;
			while (NULL != tmp && tmp->val < head->val) {
				pre = tmp;
				tmp = tmp->next;
			}
			if (NULL == pre) {
				tmp = head;
				head = head->next;
				tmp->next = head_;
				head_ = tmp;
			} else {
				pre->next = head;
				head = head->next;
				pre->next->next = tmp;
			}
		}
	}

	return head_;
}
