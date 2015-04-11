/**********************************************************************

 Given a linked list, determine if it has a cycle in it.

 Follow up:
 Can you solve it without using extra space?

**********************************************************************/

class Solution {
public:

    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
  
        while (NULL != fast && NULL != fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        
        return false;
    }
    
};
