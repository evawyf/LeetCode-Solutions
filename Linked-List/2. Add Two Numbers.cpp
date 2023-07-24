/*
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

*/

struct ListNode {
    int val; 
    ListNode *next; 
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {} 
};

// time O(max(m, n)) length of l1 and l2 
// space O(1), we don't count the answer (len: max(m,n) + 1) as part of space complexity
class Solution {
public: 
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0); 
        ListNode* head = &dummy; 
        int carry = 0; 
        while (l1 || l2 || carry) {
            if (l1) {
                carry += l1->val; 
                l1 = l1->next; 
            }
            if (l2) {
                carry += l2->val; 
                l2 = l2->next; 
            }
            head->next = new ListNode(carry % 10); 
            carry /= 10; 
            head = head->next; 
        }
        return dummy.next; 
    }
};