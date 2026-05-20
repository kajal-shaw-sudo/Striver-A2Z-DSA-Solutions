/*
problem: You are given the head of a doubly linked list.
Reverse the list in-place and return the new head of the reversed list.

Example 1
Input: head = [10, 20, 30]
Output: [30, 20, 10]

Example 2
Input: head = [1, 3, 5, 7, 9]
Output: [9, 7, 5, 3, 1]
*/

/*
class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};
*/

// brute: use a stack to store the values of the nodes while traversing the list, then traverse the list again and pop values from the stack to assign them back to the nodes in reverse order. Return the head of the modified list.
class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        stack<int> st;

        ListNode* current = head;

        while (current != NULL) {
            st.push(current->val);

            current = current->next;
        }

        current = head;

        while (current != NULL) {
            current->val = st.top();
            st.pop();

            current = current->next;
        }

        return head;
    }
};
// tc: O(n), sc: O(n)

// optimal: in-place reversal: swap the next and prev pointers of each node while traversing the list. At the end, the last node becomes the new head.
class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* current = head;

        while (current != NULL) {
            // swap the next and prev pointers of current node
            ListNode* temp = current->next;
            current->next = current->prev;
            current->prev = temp;

            // move to the next node in original order
            head = current;
            current = temp;
        }

        return head;
    }
};
// tc: O(n), sc: O(1)