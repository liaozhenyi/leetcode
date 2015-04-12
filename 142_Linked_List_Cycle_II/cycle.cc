/**********************************************************************

 Given a linked list, return the node where the cycle begins. If there is 
 no cycle, return null.

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

    ListNode *detectCycle(ListNode *head) {
        bool cycle = hasCycle(head);
        map<ListNode *, int> hash;
        
        if (false == cycle)
            return NULL;
        ListNode *cur = head;
        while (cur != NULL) {
            if (hash.find(cur) != hash.end())
                return cur;
            hash.insert(std::pair<ListNode *, int>(cur, 1));
            cur = cur->next;
        }
        
        return NULL;
    }
};
