/**********************************************************************

 Merge k sorted linked lists and return it as one sorted list. Analyze 
 and describe its complexity.

**********************************************************************/

ListNode *mergeLists(ListNode *list1, ListNode *list2) {
	ListNode *ptr1, *ptr2;
	ListNode *head, *tail;

	ptr1 = list1;
	ptr2 = list2;
	head = NULL;

	while (ptr1 && ptr2) {
		if (head == NULL) {
			if (ptr1->val < ptr2->val) {
				head = ptr1;
				ptr1 = ptr1->next;
			} else {
				head = ptr2;
				ptr2 = ptr2->next;
			}
			tail = head;
		} else {
			if (ptr1->val < ptr2->val) {
				tail->next = ptr1;
				ptr1 = ptr1->next;
			} else {
				tail->next = ptr2;
				ptr2 = ptr2->next;
			}
			tail = tail->next;
		}
	}
	if (ptr1) {
		if (head == NULL)
			head = ptr1;
		else
			tail->next = ptr1;
	}
	if (ptr2) {
		if (head == NULL)
			head = ptr2;
		else
			tail->next = ptr2;
	}
	
	return head;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
	int i, j;
	vector<ListNode *> tmp;
	vector<ListNode *>::const_iterator iter;

	if (!lists.size())
		return NULL;

	while (lists.size() > 1) {
		// merge list in lists to tmp
		for (i = 0; i < lists.size(); i+=2) {
			if (i+1 < lists.size())
				tmp.push_back(mergeLists(lists[i], lists[i+1]));
			else
				tmp.push_back(mergeLists(lists[i], NULL));
		}
		// lists.erase(all)
		lists.erase(lists.begin(), lists.end());
		// copy back from tmp to lists
		for (iter = tmp.begin(); iter != tmp.end(); iter++)
			lists.push_back(*iter);
		// tmp.erase(all)
		tmp.erase(tmp.begin(), tmp.end());
	}
	return lists[0];
}

ListNode *createList(int *array, int size) {
	ListNode *head, *tail, *node;

	head = NULL;

	for (int i = 0; i < size; i++) {
		node = new ListNode(array[i]);
		if (!head) {
			head = node;
			tail = node;
		} else {
			tail->next = node;
			tail = tail->next;
		}
	}
	return head;
}

void deleteList(ListNode *list) {
	ListNode *ptr = list, *cur;

	while (ptr) {
		cur = ptr;
		ptr = ptr->next;
		delete cur;
	}
}

/* 2nd round: use heap */
void heapify(vector<ListNode *> &arr, int pos) {
	int size = arr.size();
	int idx = 2*pos + 1;

	while (idx < size) {
		if (idx+1 < size && arr[idx+1]->val < arr[idx]->val)
			++idx;
		if (arr[pos]->val < arr[idx]->val)
			break;
		ListNode *tmp = arr[pos];
		arr[pos] = arr[idx];
		arr[idx] = tmp;

		pos = idx;
		idx = 2*pos + 1;
	}
}

void heapSort(vector<ListNode *> &arr) {
	int idx = arr.size()/2 - 1;

	for (int i = idx; i >= 0; --i)
		heapify(arr, i);
}

void getMinNode(vector<ListNode *> &arr) {
	ListNode *min = arr[0];

	arr[0] = arr[0]->next;
	if (NULL == arr[0]) {
		arr[0] = arr.back();
		arr.pop_back();
	}
	heapify(arr, 0);

	return min;
}

ListNode *mergeKLists(vector<ListNode *>& lists) {
	vector<ListNode *> arr = vector<ListNode *>();
	ListNode *head = NULL, *tail = NULL;

	for (auto &l: lists) {
		if (NULL != l) {
			arr.push_back(l);
		}
	}

	heapSort(arr);

	while (arr.size()) {
		ListNode *l = getMinNode(arr);
		if (NULL == head) {
			head = l;
			tail = l;
		} else {
			tail->next = l;
			tail = l;
		}
	}

	return head;
}
