/**
 * @file subtree_of_another_tree.cpp
 * @brief LeetCode 572: Subtree of Another Tree
 * 
 * @details
 * Given the roots of two binary trees 'root' and 'subRoot', returns true if 
 * there is a subtree of 'root' with the same structure and node values of 'subRoot'.
 * 
 * @b Foundational_Algorithmic_Insights:
 * The problem uses a dual-layer Depth-First Search (DFS). The outer recursion 
 * traverses every node in the primary tree, treating each node as a candidate 
 * root. The inner recursion ('isIdentical') structurally validates whether the 
 * candidate subtree matches the target subtree. Short-circuit evaluation ('||') 
 * ensures that once a match is identified anywhere in the tree, recursive 
 * exploration immediately unwinds to save clock cycles.
 * 
 * @b Complexity_Analysis:
 * - Time Complexity: O(N * M)
 *   In the worst case (e.g., highly repetitive values or perfect binary trees), 
 *   the 'isIdentical' check running O(M) time is called for every node in the 
 *   main tree O(N), where N is the number of nodes in 'root' and M is the 
 *   number of nodes in 'subRoot'.
 * - Space Complexity: O(H_root) or O(N) worst-case
 *   The memory footprint is determined by the maximum depth of the call stack. 
 *   In balanced trees, this is O(log N). In skewed/degenerate trees (linked lists), 
 *   it degrades to O(N). The inner function uses at most O(H_subRoot) space.
 */

#include <iostream>

// Definition for a binary tree node provided by LeetCode.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    bool isIdentical(const TreeNode* p, const TreeNode* q)
    {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
    }
public:
    bool isSubtree(const TreeNode* root, const TreeNode* subRoot)
    {
        if (!root) return false;
        
        if (isIdentical(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main()
{
    Solution sol;
    // root = [4,2,7,1,3,6,9]
    TreeNode root1(1);
    TreeNode root2(3);
    TreeNode root3(2, &root1, &root2);
    TreeNode root4(6);
    TreeNode root5(9);
    TreeNode root6(7, &root4, &root5);
    TreeNode root(4, &root3, &root6);

    std::cout << (sol.isSubtree(&root, &root6) ? "YES!" : "NO!") << std::endl;
}