#include <iostream>
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

class Solution
{
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        TreeNode *temp_left = root->left;
        root->left = root->right;
        root->right = temp_left;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr) return 0;
        int left_count  = 0;
        int right_count = 0;

        left_count = maxDepth(root->left);
        right_count = maxDepth(root->right);

        return (right_count > left_count) ? right_count + 1 : left_count + 1;
    }

    void printTreeInOrder(TreeNode* root)
    {
        if (root == nullptr) return;
        
        printTreeInOrder(root->left);       // Go left
        std::cout << root->val << ", ";      // Print self
        printTreeInOrder(root->right);      // Go right
    }

    void printTreeBFS(TreeNode* root)
    {
        if (root == nullptr) {
            std::cout << "[]" << std::endl;
            return;
        }
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        std::cout << "[";
        bool first = true;
        
        while (!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if (!first) std::cout << ", ";
            first = false;
            
            if (curr != nullptr)
            {
                std::cout << curr->val;
                // Add children to the queue to print on the next level
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }
            else
            {
                std::cout << "null";
            }
        }
        std::cout << "]" << std::endl;
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
    sol.printTreeInOrder(&root);
    std::cout << "\n";
    sol.printTreeBFS(&root);

    sol.invertTree(&root);
    sol.printTreeInOrder(&root);
    std::cout << "\n";
    sol.printTreeBFS(&root);

    return 0;
}