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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while (temp != NULL) {
            ListNode* kNode = temp;

            int count = 0;
            while (count < k && kNode != NULL) {
                kNode = kNode->next;
                count++;
            }

            if (count < k) {
                if (prevNode != NULL) {
                    prevNode->next = temp;
                }
                break;
            }

            ListNode* nextNode = kNode;
            ListNode* prev = NULL;
            ListNode* curr = temp;

            while (curr != nextNode) {
                ListNode* front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }

            if (temp == head) {
                head = prev;
            } else {
                prevNode->next = prev;
            }

            prevNode = temp;
            temp = nextNode;
        }

        return head;
        
    }
};