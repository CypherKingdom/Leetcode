/*
    Medium: Add Two Numbers
    You are given two non-empty linked lists representing two non-negative integers.
    The digits are stored in reverse order, and each of their nodes contains a single digit.
    Add the two numbers and return the sum as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Example 1:
    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.
    Example 2:
    Input: l1 = [0], l2 = [0]
    Output: [0]
    Example 3:
    Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    Output: [8,9,9,9,0,0,0,1]

    Constraints:
    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.
*/

/*
    Adding two non-negative integers represented as linked lists and
    returns their sum as a new linked list:
    Purpose:
    Each input linked list (l1 and l2) represents a number where digits are stored in reverse order (e.g., 123 is stored as 3 -> 2 -> 1).
    The task is to calculate the sum of these numbers digit by digit, accounting for any carry, and return the result as a linked list.
    Key Steps:
    Initialization: A carry variable is introduced to handle cases where the sum of digits exceeds 9.
    For example, summing 7 and 8 results in carry = 1 for the next step.
    The loop processes corresponding digits of l1 and l2 by adding them along with the current carry.
    A new node is created for each digit of the resulting sum (modulo 10), and the carry is updated as sum / 10.
    Edge Cases:
    If one list becomes nullptr before the other, the remaining digits of the other list are processed.
    If there's a leftover carry after processing both lists, it is added as a new node at the end.
    Efficiency:
    The function processes each node in both linked lists exactly once, resulting in a time complexity of O(max(n, m)),
    where n and m are the lengths of l1 and l2, respectively.
    Result:
    The function constructs a new linked list where each node represents a digit of the sum, stored in reverse order
    (consistent with the input format).
*/

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l1_head = l1;
        ListNode *l2_head = l2;
        int carry = 0, x, y;
        if (l1 == nullptr)
            x = l2->val + carry;
        else if (l2 == nullptr)
            x = l1->val + carry;
        else
            x = l1->val + l2->val + carry;
        carry = 0;
        y = x % 10;
        carry = x / 10;
        ListNode *l3 = new ListNode(y);
        ListNode *l3_head = l3;
        l3_head->next = l3->next;
        if (l1 != nullptr)
            l1 = l1->next;
        if (l2 != nullptr)
            l2 = l2->next;
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 == nullptr)
                x = l2->val + carry;
            else if (l2 == nullptr)
                x = l1->val + carry;
            else
                x = l1->val + l2->val + carry;
            carry = 0;
            y = x % 10;
            carry = x / 10;
            l3->next = new ListNode(y);
            l3 = l3->next;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        if (carry != 0)
            l3->next = new ListNode(carry);
        return l3_head;
    }
};