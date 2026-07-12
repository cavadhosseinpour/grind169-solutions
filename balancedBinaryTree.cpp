#include <iostream>
#include <cmath>

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
    int helperDepth(TreeNode* root)
    {
        if (!root) return 0;

        int left_depth {0};
        int right_depth {0};

        left_depth = helperDepth(root->left);
        if (left_depth == -1) return -1;
        right_depth = helperDepth(root->right);
        if (right_depth == -1) return -1;

        if (std::abs(left_depth - right_depth) > 1)
        {
            return -1;
        }
        else
        {
            return std::max(left_depth, right_depth) + 1;
        }
    }
public:
    bool isBalanced(TreeNode* root)
    {
        if (!root) return true;

        return helperDepth(root) != -1;
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

    std::cout << (sol.isBalanced(&root) ? "The Tree is Balanced!\n" : "The tree is Not Balanced!\n");
    return 0;
}