#include <iostream>
#include <climits>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findMax(TreeNode* root) {
    if (root == nullptr)
        return INT_MIN;
    return std::max(root->val, std::max(findMax(root->left), findMax(root->right)));
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(18);

    int maxElement = findMax(root);
    std::cout << "Maximum element in the binary tree is: " << maxElement << std::endl;

    return 0;
}
