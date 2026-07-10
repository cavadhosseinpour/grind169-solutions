/*
# LeetCode 235: Lowest Common Ancestor of Binary Search Tree
- **Difficulty:** Easy
- **Topics:** BST, DFS, Recursion

## 1. Conceptual Approach
*What is the core trick to this problem?*
- Example: Since it's a BST, the LCA is the exact split point where `p` and `q` diverge.

## 2. Corner Cases / Edge Cases Considered
- What if `p` or `q` is the root node itself?
- What if the tree only has 1 or 2 nodes?

## 3. Code (Iterative vs. Recursive)
[Insert clean, commented code here]

## 4. Complexity Analysis
- **Time Complexity:** O(H) because we only traverse down the height of the tree.
- **Space Complexity:** O(1) for iterative as we only use a pointer; O(H) for recursive due to the call stack.

## 5. Key Takeaways / Mistakes Made
- *Example:* I originally forgot the `return` keyword in my recursive calls, 
causing the answer to get lost as it bubbled up.
Remember to pass recursive results back up the chain!

*/
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

// Use INT_MIN to represent LeetCode's "null"
const int null = INT_MIN;

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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root) return nullptr;

        while (root)
        {
            if (p->val < root->val && q->val < root->val)
            {
                root = root->left;
            }
            else if (p->val > root->val && q->val > root->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
/*
// How to do it recursively:
        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            return root;
        }
*/

        return nullptr;
    }

    // standard iterative code that LeetCode uses to turn an array like [6,2,8] into a tree of pointers

    // The Function LeetCode Uses Under the Hood
    TreeNode* buildTree(const std::vector<int>& arr) {
        if (arr.empty() || arr[0] == null) return nullptr;

        // 1. Create the root node using 'new' (Pointer Approach)
        TreeNode* root = new TreeNode(arr[0]);
        
        // 2. Use a queue to keep track of nodes awaiting children
        std::queue<TreeNode*> q;
        q.push(root);

        int i = 1; // Index pointer for our input array
        while (!q.empty() && i < arr.size()) {
            TreeNode* current = q.front();
            q.pop();

            // 3. Process the Left Child
            if (i < arr.size() && arr[i] != null) {
                current->left = new TreeNode(arr[i]);
                q.push(current->left); // Push to queue so it can get its own children later
            }
            i++;

            // 4. Process the Right Child
            if (i < arr.size() && arr[i] != null) {
                current->right = new TreeNode(arr[i]);
                q.push(current->right); // Push to queue so it can get its own children later
            }
            i++;
        }

        return root;
    }
};

int main()
{
    Solution sol;
    //root = [6,2,8,0,4,7,9,null,null,3,5], p=2, q=8
    TreeNode root1(3);
    TreeNode root2(5);
    TreeNode root3(4, &root1, &root2);
    TreeNode root4(0);
    TreeNode root5(2, &root4, &root3);
    TreeNode root6(7);
    TreeNode root7(9);
    TreeNode root8(8, &root6, &root7);
    TreeNode root(6, &root5, &root8);

    // Or use the standard array to TreeNode builder function
    std::vector<int> root_arr {6,2,8,0,4,7,9,null,null,3,5};
    TreeNode* root_from_arr = sol.buildTree(root_arr);

    std::cout << "The LCA of BTS of root3 & root6 is: " << sol.lowestCommonAncestor(&root, &root5, &root8)->val << std::endl;
    std::cout << "The LCA of BTS of root3 & root6 is: " << sol.lowestCommonAncestor(root_from_arr, &root5, &root8)->val << std::endl;
    return 0;
}