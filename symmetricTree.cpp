#include <iostream>
#include <queue>
#include <stack>
#include <utility>

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
 * @file LeetCode101_SymmetricTree.cpp
 * @brief LeetCode 101 - Symmetric Tree (Study Sheet & Architecture Reference)
 * 
 * Foundational Algorithmic Insights:
 * 1. Symmetry as a Mirroring Operation: A binary tree is symmetric if and only if 
 *    its left and right subtrees are mirror images of each other. This shifts the 
 *    problem space from checking a single property on an isolated node to a 
 *    simultaneous pairwise comparison between two distinct structural pathways.
 * 2. Structural Topology vs. Node Value: Verification must validate both topological 
 *    isomorphism (the structures mirror perfectly) and value equivalence (corresponding 
 *    nodes hold identical data).
 * 3. Duality of Search Orders: The problem can be modeled using Depth-First Search (DFS) 
 *    to evaluate deep mirror paths explicitly, or Breadth-First Search (BFS) to validate 
 *    level-by-level structural symmetry.
 * 
 * Complexity Breakdowns:
 * -------------------------------------------------------------------------------------
 * Approach 1: Recursive DFS (Divide and Conquer)
 *   - Time Complexity: O(N), where N is the total number of nodes in the tree. We must 
 *     traverse each node exactly once to verify symmetry.
 *   - Space Complexity: O(H), where H is the maximum height of the tree, representing 
 *     the call stack depth. In the worst-case (skewed tree), O(H) becomes O(N). In the 
 *     best-case (perfectly balanced tree), it optimizes to O(log N).
 * 
 * Approach 2: Iterative DFS (Explicit System Stack Simulation via std::stack)
 *   - Time Complexity: O(N), visiting every node exactly once.
 *   - Space Complexity: O(H), mirroring the recursive approach space layout by shifting 
 *     the frame allocation from the OS runtime call stack to heap allocation via std::stack.
 * 
 * Approach 3: Iterative BFS (Level-by-Level Validation via std::queue)
 *   - Time Complexity: O(N), validating all node values and paths.
 *   - Space Complexity: O(W), where W is the maximum width of the binary tree. In a 
 *     perfectly complete binary tree, the leaf level contains approximately N/2 nodes, 
 *     yielding a space complexity of O(N) in the worst-case boundary.
 * -------------------------------------------------------------------------------------
 */

class Solution
{
private:
    /**
     * @brief Helper function for Approach 1 to recursively determine if two subtrees mirror.
     * @param left_root Pointer to the root of the left mirroring subtree path.
     * @param right_root Pointer to the root of the right mirroring subtree path.
     * @return true if subtrees are mirrors of each other, false otherwise.
     */
    bool isMirror(TreeNode* left_root, TreeNode* right_root)
    {
        // Base case: both nodes are structurally null, verifying symmetry along this path.
        if (!left_root && !right_root) return true;
        // Base case: structural mismatch (one node exists, the other is null).
        if (!left_root || !right_root) return false;
        // Base case: structural alignment exists, but the values do not match.
        if (left_root->val != right_root->val) return false;
        
        // Step-down recursive step: Cross-match outer children and inner children.
        return isMirror(left_root->left, right_root->right) && 
               isMirror(left_root->right, right_root->left);
    }

public:
    /**
     * @brief Approach 1: Recursive Depth-First Search (DFS)
     * Leverages the implicit call stack to perform a top-down, divide-and-conquer analysis.
     */
    bool isSymmetricRecursive(TreeNode* root)
    {
        if (!root) return true;

        return isMirror(root->left, root->right);
    }

    /**
     * @brief Approach 2: Iterative Depth-First Search (DFS)
     * Mitigates call stack overflow constraints by utilizing an explicit stack containing pairs.
     */
    bool isSymmetricIterativeDFS(TreeNode* root)
    {
        if (!root) return true;

        std::stack<std::pair<TreeNode*, TreeNode*>> nodes_stack;
        nodes_stack.push({root->left, root->right});

        while (!nodes_stack.empty())
        {
            // Leverage modern C++ structured binding for layout readability and clean state extraction
            auto [left_node, right_node] = nodes_stack.top();
            nodes_stack.pop();

            // Symmetrical base path terminated safely; skip frame insertion
            if (!left_node && !right_node)
            {
                continue;
            }
            // Topology asymmetry detected
            if (!left_node || !right_node)
            {
                return false;
            }
            // Value mismatch detected
            if (left_node->val != right_node->val)
            {
                return false;
            }

            // Push nodes into stack ensuring mirror alignment pairs are pulled sequentially
            nodes_stack.push({left_node->left, right_node->right}); // Outer mirror comparison
            nodes_stack.push({left_node->right, right_node->left}); // Inner mirror comparison
        }

        return true;
    }

    /**
     * @brief Approach 3: Iterative Breadth-First Search (BFS)
     * Leverages a queue to process structural symmetry level-by-level (FIFO scheduling).
     */
    bool isSymmetricIterativeBFS(TreeNode* root)
    {
        if (!root) return true;

        std::queue<std::pair<TreeNode*, TreeNode*>> nodes_queue;
        nodes_queue.push({root->left, root->right});

        while (!nodes_queue.empty())
        {
            auto [left_node, right_node] = nodes_queue.front();
            nodes_queue.pop();

            if (!left_node && !right_node)
            {
                continue;
            }
            if (!left_node || !right_node)
            {
                return false;
            }
            if (left_node->val != right_node->val)
            {
                return false;
            }

            // Enqueue mirror pairs. Queue order guarantees paired elements stay adjacent.
            nodes_queue.push({left_node->left, right_node->right}); // Outer mirror comparison
            nodes_queue.push({left_node->right, right_node->left}); // Inner mirror comparison
        }

        return true;
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

    std::cout << ( (sol.isSymmetricIterativeBFS(&root) && sol.isSymmetricIterativeDFS(&root) && sol.isSymmetricRecursive(&root)) ?
                "The tree is symmetric!" : "The tree is NOT symmetric!") << std::endl;

    return 0;
}