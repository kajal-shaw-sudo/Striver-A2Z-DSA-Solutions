/*
problem: You are given the head of a singly linked list. Your task is to return the number of nodes in the linked list.

Example 1
Input: head = [1, 2, 3, 4, 5]
Output: 5

Example 2
Input: head = [8, 6]
Output: 2
*/

class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;

        ListNode* current = head;

        while (current != NULL) {
            length++;
            current = current->next;
        }

        return length;
    }
};
// tc: O(n), sc: O(1)