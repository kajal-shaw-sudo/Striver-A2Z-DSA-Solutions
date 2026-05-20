/*
problem: You are given the head of a singly linked list and an integer key.
Return true if the key exists in the linked list, otherwise return false.

Example 1
Input: head = [1, 2, 3, 4], key = 3
Output: true
Explanation: The linked list is 1 → 2 → 3 → 4. The key 3 is present in the list.

Example 2
Input: head = [7, 8, 9, 10, 11], key = 5
Output: false
Explanation: The key 5 is not present in the list.
*/

/*Defination of ListNode
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

class Solution {
public:
    bool searchKey(ListNode* head, int key) {
        ListNode* current = head;

        while (current != NULL) {
            if (current->val == key) {
                return true;
            }

            current = current->next;
        }

        return false;
    }
};
// tc: O(n), sc: O(1)