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
 * PROBLEM DESCRIPTION:
 * Given the head of a singly linked list, reverse the list, and return its new head.
 * 
 * FOUNDATIONAL ALGORITHMIC INSIGHTS:
 * The iterative approach uses a sliding three-pointer window to reverse structural
 * links in-place. By maintaining references to the previous, current, and next nodes,
 * we can safely flip the current node's directional arrow backward without losing 
 * track of the remaining unvisited nodes ahead.
 * 
 * COMPLEXITY ANALYSIS:
 * - Time Complexity: O(n) - We perform a single sequential pass through the list of n nodes.
 * - Space Complexity: O(1) - The pointers are mutated in-place using a constant amount of memory.
 */
    ListNode* reverseList(ListNode* head)
    {
        if (!head) return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr)
        {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
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
    ListNode* new_head = sol.reverseList(&n);
    ListNode* print_new_head = new_head;
    while (print_new_head)
    {
        std::cout << print_new_head->val << ", ";
        print_new_head = print_new_head->next;
    }
    std::cout << std::endl;
    return 0;
}

// Alternative approach 1 - Reverse a singly linked list using a recursive strategy
/**
 * PROBLEM DESCRIPTION:
 * Reverse a singly linked list using a recursive strategy.
 * 
 * FOUNDATIONAL ALGORITHMIC INSIGHTS:
 * This uses a bottom-up recursion strategy. We traverse to the end of the list first.
 * As the call stack unwinds backward, each node commands the node ahead of it 
 * to point back to itself (`head->next->next = head`), breaking the old forward link.
 * 
 * COMPLEXITY ANALYSIS:
 * - Time Complexity: O(n) - Visits every single node exactly once.
 * - Space Complexity: O(n) - Uses implicit memory allocations on the call stack up to depth n.
 */
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: empty list or reaching the new head (the final node)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Traverse to the very end of the list first
        ListNode* reversedListHead = reverseList(head->next);
        
        // Re-wire the pointers as the call stack unwinds
        head->next->next = head;
        head->next = nullptr;
        
        return reversedListHead;
    }
};
*/

// Alternative approach 2 - using an explicit Stack data structure

// #include <stack>

/**
 * PROBLEM DESCRIPTION:
 * Reverse a singly linked list using an explicit Stack data structure.
 * 
 * FOUNDATIONAL ALGORITHMIC INSIGHTS:
 * Stacks operate on a Last-In-First-Out (LIFO) basis. By pushing all node addresses 
 * sequentially onto the stack, the original tail node naturally pops out first. We then 
 * pop elements one by one, linking them together to construct the reversed list.
 * 
 * COMPLEXITY ANALYSIS:
 * - Time Complexity: O(n) - Requires two passes: one to populate the stack, one to reconstruct links.
 * - Space Complexity: O(n) - Requires explicit heap storage to hold references to all n nodes.
 */
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        std::stack<ListNode*> nodeStack;
        ListNode* currentNode = head;
        
        // Pass 1: Push all node memory addresses onto the stack
        while (currentNode != nullptr) {
            nodeStack.push(currentNode);
            currentNode = currentNode->next;
        }
        
        // Establish the new head of the reversed list
        ListNode* newHead = nodeStack.top();
        nodeStack.pop();
        
        // Pass 2: Reconstruct structural links sequentially
        currentNode = newHead;
        while (!nodeStack.empty()) {
            currentNode->next = nodeStack.top();
            nodeStack.pop();
            currentNode = currentNode->next;
        }
        
        // The original head node is now the tail; it must point to nothing
        currentNode->next = nullptr;
        
        return newHead;
    }
};
*/
