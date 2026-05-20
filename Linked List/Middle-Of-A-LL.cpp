// problem link: https://leetcode.com/problems/middle-of-the-linked-list/description/

/*
problem: Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
*/

//brute: count the total number of nodes in the list, then traverse again to the middle node and return it.
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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        int length = 0;

        ListNode* current = head;

        while (current != NULL) {
            length++;
            current = current->next;
        }

        int mid = length / 2;

        current = head;

        while (mid--) {
            current = current->next;
        }

        return current;
    }
};
// tc: O(2n) → O(n), sc: O(1)

// optimal: Tortoise and Hare method - use two pointers, one slow and one fast. Move the slow pointer by 1 step and the fast pointer by 2 steps in each iteration. When the fast pointer reaches the end of the list, the slow pointer will be at the middle node.
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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
// tc: O(n/2) → O(n), sc: O(1)

// Note: Both simplify to O(n) asymptotically, but the constant factors differ — brute does 2n steps, optimal does n/2 steps. The Tortoise and Hare is 4x faster in practice.