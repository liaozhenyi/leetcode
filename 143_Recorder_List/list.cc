/**********************************************************************

 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 
 You must do this in-place without altering the nodes' values.
 
 For example,
 Given {1,2,3,4}, reorder it to {1,4,2,3}.

**********************************************************************/

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *head_ = NULL, *tmp;
        
        while (head) {
            if (NULL == head_) {
                head_ = head;
                head = head->next;
                head_->next = NULL;
            } else {
                tmp = head;
                head = head->next;
                tmp->next = head_;
                head_ = tmp;
            }
        }
        
        return head_;
    }
    
    ListNode *mergeList(ListNode *list1, ListNode *list2) {
        ListNode *pre = list1, *cur = list2, *next;
        
        while (cur) {
            next = pre->next;
            pre->next = cur;
            cur = cur->next;
            pre->next->next = next;
            pre = next;
        }
        return list1;
    }

    void reorderList(ListNode *head) {
        if (NULL == head)
            return ;
        
        ListNode *mid, *end;
        mid = head;
        end = head->next;
        while (NULL != end && NULL != end->next) {
            mid = mid->next;
            end = end->next->next;
        }
        
        ListNode *list1 = head, *list2 = mid->next;
        mid->next = NULL;
        list2 = reverseList(list2);
        list1 = mergeList(list1, list2);
        
        head = list1;
    }
};
