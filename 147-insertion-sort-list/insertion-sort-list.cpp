/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != nullptr) {

            // Already in correct position
            if (prev->val <= curr->val) {
                prev = curr;
                curr = curr->next;
                continue;
            }

            // Find position where curr should be inserted
            ListNode* temp = dummy;

            while (temp->next->val <= curr->val) {
                temp = temp->next;
            }

            // Remove curr from its current position
            prev->next = curr->next;

            // Insert curr before temp->next
            curr->next = temp->next;
            temp->next = curr;

            // Move to next unsorted node
            curr = prev->next;
        }

        return dummy->next;
    }
};