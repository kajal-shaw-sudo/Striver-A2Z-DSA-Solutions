/*
problem: Given the head of a singly linked list, delete the head of the linked list and return the head of the modified list. The head is the first node of the linked list.

Example 1
Input: linkedList = [1, 2, 3]
Output: [2, 3]
Explanation:
The first node was removed.

Example 2
Input: linkedList = [1]
Output: []
Explanation:
Note that the head of the linked list gets changed.
*/

/*
Definition of singly linked list:
class ListNode{
  
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
public:
    ListNode* deleteHead(ListNode* &head) {
        if (head == NULL || head->next == NULL) {
            delete head;
            return NULL;
        }

        ListNode* newHead = head->next;

        delete head;

        return newHead;
    }
};
// tc: O(1), sc: O(1)