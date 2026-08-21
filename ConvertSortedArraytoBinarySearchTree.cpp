#include <vector>
#include <iostream>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

/**
 * @file LeetCode108_SortedArrayToBST.cpp
 * @brief Problem Description: Convert a sorted integer array into a height-balanced BST.
 *
 * Foundational Algorithmic Insights:
 * 1. The midpoint of a sorted array slice represents the optimal root node to ensure 
 *    height balance across subtrees.
 * 2. This problem maps perfectly to a Divide-and-Conquer (DFS) approach where the left 
 *    and right segments of the midpoint recursively form the left and right subtrees.
 * 3. Passing the data vector by constant reference avoids expensive deep-copy operations.
 *
 * Complexity Analysis:
 * - Time Complexity: O(N)
 *   Every element in the vector is visited exactly once to create its corresponding TreeNode.
 * - Space Complexity: O(log N)
 *   The maximum depth of the recursive call stack is bounded by the height of the balanced 
 *   tree, which scales logarithmically with respect to the total number of nodes N.
 */

class Solution
{
private:
    /**
     * @brief Recursively builds a height-balanced BST from a bounded subarray slice.
     * @param nums The source sorted array passed by constant reference.
     * @param left The lower bound index of the current subarray slice.
     * @param right The upper bound index of the current subarray slice.
     * @return TreeNode* A pointer to the root node of the constructed subtree.
     */
    TreeNode* buildBalancedTree(const std::vector<int>& nums, int left, int right)
    {
        // Base case: Pointers have crossed; no elements remain in this window segment.
        if (left > right) return nullptr;

        // Prevent potential integer overflow during midpoint evaluation.
        int mid = left + (right - left) / 2;

        // Construct the root of the current subtree using the midpoint element.
        TreeNode* currentRoot = new TreeNode(nums[mid]);

        // Recursively isolate and construct the left and right child subtrees.
        currentRoot->left = buildBalancedTree(nums, left, mid - 1);
        currentRoot->right = buildBalancedTree(nums, mid + 1, right);

        return currentRoot;
    }

public:
    /**
     * @brief Entry point function to convert a sorted array into a height-balanced BST.
     * @param nums The source sorted vector.
     * @return TreeNode* A pointer to the root of the generated BST.
     */
    TreeNode* sortedArrayToBST(const std::vector<int>& nums)
    {
        // Handle empty vector edge case cleanly via the helper's internal base case.
        return buildBalancedTree(nums, 0, static_cast<int>(nums.size()) - 1);
    }
};

int main()
{
    std::vector<int> nums = {-10,-3,0,5,9};
    Solution sol;
    std::cout << "The pointer to the root is: " << sol.sortedArrayToBST(nums) << std::endl;
}


/*
#include <vector>
#include <stack>


 // @file LeetCode108_SortedArrayToBST_Iterative.cpp
 // @brief Problem Description: Convert a sorted integer array into a height-balanced BST iteratively.
 //
 // Foundational Algorithmic Insights:
 // 1. Simulates recursive Depth-First Search (DFS) using an explicit heap-allocated std::stack.
 // 2. Uses a helper structure to tightly couple array bounds with their destination pointer slots.
 // 3. Utilizing a pointer-to-pointer (TreeNode**) abstracts away parent-child linkage decisions.
 // 4. Pushing the right child segment before the left segment preserves traditional pre-order processing.
 //
 // Complexity Analysis:
 // - Time Complexity: O(N)
 //   Every element index range is pushed and popped from the stack exactly once to instantiate a node.
 // - Space Complexity: O(log N)
 //   The stack size safely mimics the depth of a height-balanced tree, scaling logarithmically with N.


class Solution {
private:
    
     // @brief Structural packet tracking subarray ranges and their destination parent nodes.
    
    struct SubtreeRange {
        int left;
        int right;
        TreeNode** parentSlot; // Ptr to the specific parent pointer slot requiring assignment

        SubtreeRange(int l, int r, TreeNode** slot) 
            : left(l), right(r), parentSlot(slot) {}
    };

public:
    
     // @brief Iterative entry point function converting a sorted vector into a balanced BST.
     // @param nums The source sorted vector passed by constant reference.
     // @return TreeNode* A pointer to the root of the generated BST.

    TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        TreeNode* root = nullptr;
        std::stack<SubtreeRange> workStack;

        // Push the base array range targeted directly at the root pointer reference.
        workStack.push(SubtreeRange(0, static_cast<int>(nums.size()) - 1, &root));

        while (!workStack.empty()) {
            SubtreeRange current = workStack.top();
            workStack.pop();

            // Equivalent to the recursive base case (pointers crossed)
            if (current.left > current.right) {
                *current.parentSlot = nullptr;
                continue;
            }

            // Standard mid-point calculation avoiding integer overflow
            int mid = current.left + (current.right - current.left) / 2;

            // Instantiate node and link directly into parent slot using dereferenced pointer
            *current.parentSlot = new TreeNode(nums[mid]);
            TreeNode* currentNode = *current.parentSlot;

            // Push the right child boundary configuration first (processed last)
            workStack.push(SubtreeRange(mid + 1, current.right, &(currentNode->right)));

            // Push the left child boundary configuration second (processed first)
            workStack.push(SubtreeRange(current.left, mid - 1, &(currentNode->left)));
        }

        return root;
    }
};



*/
