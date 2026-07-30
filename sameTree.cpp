#include <iostream>
#include <stack>
#include <utility>
#include <queue>

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
 * @file SameTree.cpp
 * @brief LeetCode 100: Same Tree
 * 
 * Foundational Algorithmic Insights:
 * The problem utilizes a recursive Depth-First Search (DFS) strategy to perform
 * a simultaneous pre-order traversal on two binary trees. By verifying the 
 * identity of the current nodes first (base cases), the algorithm establishes 
 * a structural contract. It then propagates this verification down to the left 
 * and right child pairs using the logical AND (&&) operator. This enables 
 * short-circuit evaluation: if the left subtrees mismatch, the right subtrees 
 * are never traversed, optimizing execution runtime.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(min(N, M))
 *   Where N and M are the total number of nodes in tree 'p' and tree 'q', respectively.
 *   The algorithm visits each node exactly once. It terminates early the moment 
 *   a structural or value mismatch is detected.
 * - Space Complexity: O(min(H1, H2))
 *   Where H1 and H2 are the heights of tree 'p' and tree 'q'. This space is 
 *   consumed by the implicit function call stack during recursion. In the worst 
 *   case of a completely skewed tree, the complexity degrades to O(min(N, M)). 
 *   In the best case of a perfectly balanced tree, the space complexity is O(log(min(N, M))).
 */

class Solution
{
public:

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (!p && !q)
        {
            return true;
        }
        if (!p || !q)
        {
            return false;
        }
        if (p->val != q->val)
        {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

/**
 * @file SameTree_Iterative.cpp
 * @brief Leetcode 100: Same Tree (Iterative Solution)
 * 
 * Foundational Algorithmic Insights:
 * This approach explicitly replicates the operating system's recursive call stack 
 * using an iterative Depth-First Search (DFS) via std::stack. By pushing pairs of 
 * nodes onto a single stack, we ensure synchronized structural evaluation. 
 * To match the exact logic of the recursive version, we push child pointers 
 * unconditionally (even if null). The validation rules at the top of the loop 
 * act as the exact mirrors of the recursive base cases.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(min(N, M)) 
 *   Every node pair is pushed and popped from the stack at most once.
 * - Space Complexity: O(min(H1, H2)) 
 *   The stack stores the paths from the root to the current leaf nodes. In a 
 *   completely skewed tree, this consumes O(min(N, M)) memory space.
 */

    bool isSameTree_Stack(TreeNode* p, TreeNode* q)
    {
        std::stack<std::pair<TreeNode*, TreeNode*>> traversal_stack;
        traversal_stack.push({p, q});
        
        while (!traversal_stack.empty())
        {
            auto [p_curr, q_curr] = traversal_stack.top();
            traversal_stack.pop();

            if (!p_curr && !q_curr)
            {
                continue;
            }
            if (!p_curr || !q_curr)
            {
                return false;
            }
            if (p_curr->val != q_curr->val)
            {
                return false;
            }

            traversal_stack.push({p_curr->right, q_curr->right});
            traversal_stack.push({p_curr->left, q_curr->left});
        }
        return true;
    }

    /**
     * @file SameTree_BFS.cpp
     * @brief Leetcode 100: Same Tree (Iterative BFS Solution)
     * 
     * Foundational Algorithmic Insights:
     * This approach implements a Breadth-First Search (BFS) using a std::queue to 
     * validate the identity of two binary trees level-by-level (layer-by-layer). 
     * Corresponding node pairs from tree 'p' and tree 'q' are queued together.
     * The loop continuously dequeues a pair, subjects them to structural validation 
     * tests, and inserts their children back into the queue. Because a queue functions
     * on a First-In, First-Out (FIFO) basis, pushing the left children before the 
     * right children guarantees a clean, left-to-right horizontal traversal.
     * 
     * Complexity Analysis:
     * - Time Complexity: O(min(N, M))
     *   Every node pair is enqueued and dequeued from the processing queue at most once.
     *   The loop terminates immediately upon finding any structural or value inequality.
     * - Space Complexity: O(min(W1, W2))
     *   Where W1 and W2 are the maximum widths (maximum number of nodes at any single layer)
     *   of tree 'p' and tree 'q'. In a perfectly balanced binary tree, the bottom layer 
     *   contains roughly N/2 nodes, making the worst-case space complexity O(min(N, M)). 
     *   Note that while Big-O matches DFS for skewed structures, BFS consumes significantly 
     *   more memory on highly balanced, wide trees due to tracking full horizontal levels.
     */

    bool isSameTree_BFS(TreeNode* p, TreeNode* q)
    {
        // Use a FIFO queue to enforce a strict level-by-level horizontal traversal
        std::queue<std::pair<TreeNode*, TreeNode*>> traversal_queue;
        
        // Seed the queue with the starting roots
        traversal_queue.push({p, q});
        
        while (!traversal_queue.empty())
        {
            // Extract the oldest waiting pair at the front of the queue
            auto [p_curr, q_curr] = traversal_queue.front();
            traversal_queue.pop();
            
            // Base Case 1 Mirror: Both endpoints are null leaf spaces.
            // Move onto the next structural pair waiting in line.
            if (!p_curr && !q_curr)
            {
                continue;
            }
            
            // Base Case 2 Mirror: Asymmetric structure detected.
            if (!p_curr || !q_curr)
            {
                return false;
            }
            
            // Base Case 3 Mirror: Disparate internal node values detected.
            if (p_curr->val != q_curr->val)
            {
                return false;
            }
            
            // Enqueue child paths unconditionally to check layout matches.
            // Since it's FIFO, pushing left first means left gets checked first.
            traversal_queue.push({p_curr->left, q_curr->left});
            traversal_queue.push({p_curr->right, q_curr->right});
        }
        
        // All layers matched flawlessly
        return true;
    }
};

/*
 -  On a deep, narrow, linear tree (highly unbalanced/skewed):
    BFS uses \(O(1)\) memory because every horizontal layer only contains 1 node.
    DFS memory scales to \(O(N)\) because it has to track the entire deep path down to the single leaf.

 -  On a perfectly balanced, wide tree: DFS uses \(O(\log N)\) memory (the height of the tree).
    BFS memory swells to \(O(N)\) because the final leaf row contains half of the entire tree's nodes
    all sitting in the queue simultaneously.

*/

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

    std::cout << (sol.isSameTree(&root, &root) ? "Same Tree!" : "NOT Same Tree!") << std::endl;
}