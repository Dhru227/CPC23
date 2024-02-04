#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void verticalSumHelper(TreeNode* root, int column, map<int, int>& sums) {
    if (root == nullptr)
        return;

    verticalSumHelper(root->left, column - 1, sums);
    sums[column] += root->val;
    verticalSumHelper(root->right, column + 1, sums);
}

void verticalSum(TreeNode* root) {
    map<int, int> sums;
    verticalSumHelper(root, 0, sums);

    for (const auto& pair : sums) {
        cout << pair.second << " ";
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    verticalSum(root);

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
