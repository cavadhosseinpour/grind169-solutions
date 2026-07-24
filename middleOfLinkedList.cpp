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
    /**
     * @brief Finds the middle node of a singly linked list.
     * 
     * Foundational Algorithmic Insights:
     * Utilizes the Tortoise and Hare (two-pointer) approach. The `fast` pointer moves 
     * at twice the velocity of the `slow` pointer. When `fast` reaches the end of the 
     * list, `slow` is precisely at the midpoint. For lists with an even number of nodes, 
     * this implementation returns the second middle node.
     * 
     * Complexity Analysis:
     * - Time Complexity:  O(n), where n is the number of nodes. The fast pointer traverses 
     *                     at most n/2 iterations.
     * - Space Complexity: O(1), utilizing a constant amount of extra memory for pointers.
     */
    ListNode* middleNode(ListNode* head)
    {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main()
{
    // Form a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode n4(5);
    ListNode n3(4, &n4);
    ListNode n2(3, &n3);
    ListNode n1(2, &n2);
    ListNode n(1, &n1);

    Solution sol;
    std::cout << "The middle of the list is: " << sol.middleNode(&n)->val << std::endl;
}