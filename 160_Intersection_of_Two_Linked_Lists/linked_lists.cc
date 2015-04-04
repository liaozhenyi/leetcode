/**********************************************************************

 Write a program to find the node at which the intersection of two singly 
 linked lists begins.


 For example, the following two linked lists:
 
 A:          a1 → a2
                    ↘
                      c1 → c2 → c3
                    ↗            
 B:     b1 → b2 → b3
 begin to intersect at node c1.
 
 
 Notes:
 
 If the two linked lists have no intersection at all, return null.
 The linked lists must retain their original structure after the function returns.
 You may assume there are no cycles anywhere in the entire linked structure.
 Your code should preferably run in O(n) time and use only O(1) memory.

**********************************************************************/

/*
 * At first I think may be we can rotate these two lists,
 * and compare them from the header, but the note notifies
 * that the lists must retain their original structure.
 *
 * If the two lists share some same nodes, their ending
 * node must be the same. So we can traversal the lists 
 * to check whether their ending node is the same, and 
 * also to count the total elements of the list; in the 
 * second traversal we can find the node.
 */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	int cntA = 0, cntB = 0;
	ListNode *curA, *curB;

	if (NULL == headA)
		curA = NULL;
	else
		for (curA = headA; curA->next != NULL; curA = curA->next)
			++cntA;
	if (NULL == headB)
		curB = NULL;
	else
		for (curB = headB; curB->next != NULL; curB = curB->next)
			++cntB;

	// now curA and curB point to their ending node separately
	if (curA != curB)
		return NULL;
	curA = headA;
	curB = headB;
	if (cntA > cntB)
		for (int i = 0; i < cntA-cntB; i++)
			curA = curA->next;
	else if (cntA < cntB)
		for (int i = 0; i < cntB-cntA; i++)
			curB = curB->next;

	while (NULL != curA) {
		if (curA == curB)
			return curA;
		curA = curA->next;
		curB = curB->next;
	}
	return NULL;
}
