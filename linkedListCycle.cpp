#include <iostream>


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
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    // Form a linked list: 3 -> 2 -> 0 -> -4 -> back to 2
    ListNode n4(-4);
    ListNode n3(0, &n4);
    ListNode n2(2, &n3);
    ListNode n1(3, &n2);
    n4.next = &n2;

    Solution sol;
    std::cout << ( sol.hasCycle(&n1) ? "There is a cycle in the list!\n" : "There is NO cycle in the list\n" );
    return 0;
}