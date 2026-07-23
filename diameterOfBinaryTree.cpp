#include <iostream>
#include <stack>
#include <unordered_map>
#include <algorithm>

/**
 * @file Solution.cpp
 * @brief LeetCode 543 - Diameter of Binary Tree
 * 
 * Foundational Algorithmic Insights:
 * The longest path between any two nodes must peak at a specific local apex node.
 * By utilizing a bottom-up post-order Depth-First Search (DFS), we compute the 
 * maximum depth of the left and right subtrees for every node. The local diameter 
 * at any node is the sum of these two depths. We maintain a running maximum of 
 * these sums while returning the node's maximum height back up the recursive call stack.
 * This completely avoids state contamination and avoids a suboptimal O(N^2) approach.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N)
 *   Every node in the binary tree is visited exactly once to calculate its height.
 * - Space Complexity: O(H)
 *   The memory overhead depends on the recursion stack, which matches the height of the tree.
 *   In the worst-case scenario (a skewed tree), H = O(N). In a balanced tree, H = O(log N).
 */

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

class Solution
{
private:
    /**
     * @brief Computes the depth of a node while updating the global maximum diameter.
     * @param root Pointer to the current tree node.
     * @param max_diameter Reference to the running maximum diameter found so far.
     * @return The maximum depth/height of the current subtree.
     */
    int maxDepth(TreeNode* root, int& max_diameter)
    {
        if (!root) return 0;

        int left_depth = maxDepth(root->left, max_diameter);
        int right_depth = maxDepth(root->right, max_diameter);

        if ( (left_depth + right_depth) > max_diameter)
        {
            max_diameter = left_depth + right_depth;
        }

        return (left_depth > right_depth) ? left_depth + 1 : right_depth + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (!root || ( !(root->left) && !(root->right) ) ) return 0;
        int max_diameter = 0;
        maxDepth(root, max_diameter);

        return max_diameter;
    }

    /*
    * Writing this code using stacks instead of recursive call stacks.
    * @file IterativeSolution.cpp
    * @brief LeetCode 543 - Diameter of Binary Tree (Iterative Stack Approach)
    * 
    * Foundational Algorithmic Insights:
    * This approach mimics the post-order traversal using an explicit std::stack. 
    * A hash map tracks the computed heights of processed nodes. A node is only 
    * popped and fully evaluated after both its left and right children have had 
    * their heights calculated and stored in the map.
    * 
    * Complexity Analysis:
    * - Time Complexity: O(N)
    *   Each node is pushed and popped from the stack a constant number of times.
    * - Space Complexity: O(N)
    *   The hash map stores the height mapping for up to N nodes.
    */

    int diameterOfBinaryTree_stack(TreeNode* root)
    {
        if (!root) return 0;

        int max_diameter = 0;
        std::stack<TreeNode*> traversl_stack;
        std::unordered_map<TreeNode*, int> node_heights;

        traversl_stack.push(root);

        while (!traversl_stack.empty())
        {
            TreeNode* current_node = traversl_stack.top();
            if(current_node->left && !node_heights.contains(current_node->left))
            {
                traversl_stack.push(current_node->left);
            }
            else if (current_node->right && !node_heights.contains(current_node->right))
            {
                traversl_stack.push(current_node->right);
            }
            else
            {
                traversl_stack.pop();
                int left_depth = (current_node->left) ? node_heights[current_node->left] : 0;
                int right_depth = (current_node->right) ? node_heights[current_node->right] : 0;

                if (left_depth + right_depth > max_diameter) max_diameter = left_depth + right_depth;

                node_heights[current_node] = 1 + std::max(left_depth, right_depth);
            }
        }
        return max_diameter;
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

    std::cout << "The max diiameter of TreeNode is: " << sol.diameterOfBinaryTree(&root) << "\n";
    std::cout << "The max diiameter of TreeNode is: " << sol.diameterOfBinaryTree_stack(&root) << "\n";

    return 0;
}