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
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {

//     }
// };

/* Linked List Node Structure
class Node {
    public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
public:
    void convertToArr(vector<ListNode*>& arr, vector<int>& mergedArr) {
        for (int i = 0; i < arr.size(); i++) {
            ListNode* temp = arr[i];
            while (temp != NULL) {
                mergedArr.push_back(temp->val);
                temp = temp->next;
            }
        }
    }
    ListNode* convertToLinkedList(vector<int>& mergedArr) {
        if (mergedArr.empty()) {
            return NULL;
        }
        ListNode* head = new ListNode(mergedArr[0]);
        ListNode* temp = head;
        for (int i = 1; i < mergedArr.size(); i++) {
            temp->next = new ListNode(mergedArr[i]);
            temp = temp->next;
        }
        return head;
    }
   ListNode* mergeKLists(vector<ListNode*>& arr) {
        vector<int> mergedArr;
        convertToArr(arr, mergedArr);
        sort(mergedArr.begin(), mergedArr.end());
        return convertToLinkedList(mergedArr);
    }
};
