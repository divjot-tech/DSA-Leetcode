/*
// Definition for a ListNode.
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* random;
    
    ListNode(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
void insertNode(Node* head) {
        Node* temp = head;

        while(temp != NULL) {
            Node* nextElement = temp->next;

            Node* newNode = new Node(temp->val);

            newNode->next = nextElement;
            temp->next = newNode;

            temp = nextElement;
        }
    }
void connectRandom(Node* head) {
        Node* temp = head;

        while(temp != NULL) {
            Node* copyNode = temp->next;

            if(temp->random) {
                copyNode->random = temp->random->next;
            }
            else {
                copyNode->random = nullptr;
            }

            temp = copyNode->next;
        }
    }
    Node* connectNext(Node* head) {
        Node* temp = head;

        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        while(temp != NULL) {
            // Attach copied node to the new list
            res->next = temp->next;
            res = res->next;

            // Restore original list
            temp->next = temp->next->next;

            temp = temp->next;
        }

        return dummyNode->next;
    }
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        insertNode(head);
        connectRandom(head);
        return connectNext(head);
        
    }
};