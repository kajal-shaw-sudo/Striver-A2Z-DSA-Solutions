/*
problem: Given the head of a singly linked list and an integer X, insert a node with value X at the head of the linked list and return the head of the modified list.

Example 1
Input: linkedList = [1, 2, 3], X = 7
Output: [7, 1, 2, 3]
Explanation:
7 was added as the 1st node.

Example 2
Input: linkedList = [], X = 7
Output: [7]
Explanation:
7 was added as the 1st node.
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
        ListNode* insertAtHead(ListNode* &head, int X) {
            ListNode* newHead = new ListNode(X, head);

            return newHead;
        }
};
// tc: O(1), sc: O(1)