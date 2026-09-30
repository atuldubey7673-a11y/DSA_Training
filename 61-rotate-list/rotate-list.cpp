
class Solution {
public:
    ListNode* findNthNode(ListNode* temp, int k) {
        int count = 1;
        while (temp != NULL) {
            if (count == k)
                return temp;
            count++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
         if (head == NULL || head->next == NULL)
            return head;
        ListNode* tail = head;
        int len = 1;
        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }
        if (k % len == 0)
            return head;
        k = k % len;
        if(k==0) return head;
        tail->next = head;
        ListNode* newTail = findNthNode(head, len - k);
        head = newTail->next;
        newTail->next = NULL;
        return head;
    }
};