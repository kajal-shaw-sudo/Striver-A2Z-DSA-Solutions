/*
problem: Given the head of a doubly linked list and an integer X, insert a node with value X before the head of the linked list and return the head of the modified list.

Example 1
Input: head = [1, 2, 3], X = 3
Output: head = [3, 1, 2, 3]
Explanation: 3 was added before the 1st node. Note that the head's value is changed.

Example 2
Input: head = [5], X = 7
Output: head = [7, 5]
*/

/**
class ListNode
{
 * Definition for doubly-linked list.
 *  public:
 *      int data;
 *      ListNode *prev;
 *      ListNode *next;
 *      ListNode() : data(0), prev(nullptr), next(nullptr) {}
 *      ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
 *      ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};
*/

class Solution {
public:
    ListNode* insertBeforeHead(ListNode* head, int X) {
        ListNode* newHead = new ListNode(X);
        newHead->next = head;

        if (head != NULL) {
            head->prev = newHead;
        }

        return newHead;
    }
};
// tc: O(1), sc: O(1)