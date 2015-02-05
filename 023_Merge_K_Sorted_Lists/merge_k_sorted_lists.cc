/**********************************************************************

 Merge k sorted linked lists and return it as one sorted list. Analyze 
 and describe its complexity.

**********************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

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

void printList(ListNode *list) {
	ListNode *ptr = list;

	while (ptr) {
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

int main(int argc, char *argv[])
{
	srand((unsigned)time(0));
	int array1[] = {1, 3, 5, 7, 9, 11};
	int array2[] = {2, 4, 6, 8, 10, 12};
	ListNode *list1, *list2, *list;
	vector<ListNode *>listVector;

	list1 = createList(array1, sizeof(array1)/sizeof(int));
	list2 = createList(array2, sizeof(array2)/sizeof(int));

	printList(list1);
	printList(list2);

	list = mergeLists(list1, list2);
	printList(list);

	deleteList(list);

	for (int i = 0; i < 1; i++)
		listVector.push_back(new ListNode(rand()%5000));

	list = mergeKLists(listVector);
	printList(list);

	deleteList(list);	

	return 0;
}
