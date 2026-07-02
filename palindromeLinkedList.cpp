#include <iostream>


 // Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr;
        while (slow != nullptr)
        {
            ListNode *next_node = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next_node;
        }


        ListNode *p1 = head;
        ListNode *p2 = prev;
        while (p2 != nullptr)
        {
            if (p1->val != p2->val)
            {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    // Correct way to build the linked list: 1 -> 2 -> 2 -> 1 -> nullptr
    ListNode* list = new ListNode(1, 
                        new ListNode(2, 
                            new ListNode(2, 
                                new ListNode(1))));
    /*
    // Alternative approach to build a singly linked list
    // Form the list: 1 -> 2 -> 2 -> 1 -> nullptr
    ListNode n4(1);
    ListNode n3(2, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);
    */
    if (sol.isPalindrome(list))
    {
        std::cout << "The list is Palindrome\n";
    }
    else
    {
        std::cout << "The list is Not Palindrome\n";
    }

    // Optional but good practice: clean up allocated memory
    while (list != nullptr) {
        ListNode* temp = list;
        list = list->next;
        delete temp;
    }
    return 0;
}