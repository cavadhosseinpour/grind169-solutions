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

class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if (!root) return 0;

        int left_length = maxDepth(root->left);
        int right_length = maxDepth(root->right);

        return (left_length > right_length) ? left_length + 1 : right_length + 1;
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

    std::cout << "The max depth of TreeNode is: " << sol.maxDepth(&root) << "\n";
}