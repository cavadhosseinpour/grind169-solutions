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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode *list3 = &dummy;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                list3->next = list1;
                list1 = list1->next;
            }
            else
            {
                list3->next = list2;
                list2 = list2->next;
            }
            list3 = list3->next;
        }
        if (list1 != nullptr)
        {
            list3->next = list1;
        }
        else
        {
            list3->next = list2;
        }
        return dummy.next;
    }

    // Recursive function to merge two sorted linked lists
    ListNode* mergeTwoLists_recursive(ListNode* list1, ListNode* list2)
    {
        // Base Case 1: If the first list is empty, return the second list
        if (!list1) return list2;
        // Base Case 2: If the second list is empty, return the first list
        if (!list2) return list1;

        // Recursive step: Determine which node has the smaller value
        if (list1->val <= list2->val)
        {
            // Link the current node to the result of the next recursive merge
            list1->next = mergeTwoLists_recursive(list1->next, list2);
            return list1; // Return the head of the merged list
        }
        else
        {
            // Link the current node to the result of the next recursive merge
            list2->next = mergeTwoLists_recursive(list1, list2->next);
            return list2; // Return the head of the merged list
        }
    }

    // Helper function to print the linked list
    void printList(ListNode* head)
    {
        while (head)
        {
            std::cout << head->val << " -> ";
            head = head->next;
        }
        std::cout << "nullptr\n";
    }
};

int main()
{
    Solution sol;
    // Creating List 1: 1 -> 3 -> 5
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    // Creating List 2: 2 -> 4 -> 6
    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    std::cout << "Original List 1: ";
    sol.printList(list1);
    std::cout << "Original List 2: ";
    sol.printList(list2);

    // Merging lists
    ListNode* mergedHead = sol.mergeTwoLists(list1, list2);

    std::cout << "Merged Sorted List: ";
    sol.printList(mergedHead);

    return 0;
}