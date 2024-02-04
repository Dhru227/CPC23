#include <iostream>
#include <map>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void verticalZigZagTraversal(TreeNode* root) {
    if (!root) return;

    map<int, vector<int>> verticalLevels;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int hd = q.front().second;
        q.pop();

        verticalLevels[hd].push_back(node->val);

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    bool leftToRight = false;
    for (auto it = verticalLevels.rbegin(); it != verticalLevels.rend(); ++it) {
        vector<int> levelNodes = it->second;
        if (leftToRight) {
            for (int i = 0; i < levelNodes.size(); ++i)
                cout << levelNodes[i] << " ";
        } else {
            for (int i = levelNodes.size() - 1; i >= 0; --i)
                cout << levelNodes[i] << " ";
        }
        leftToRight = !leftToRight;
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

    cout << "Vertical Zig-Zag Traversal: ";
    verticalZigZagTraversal(root);
    cout << endl;

    return 0;
}
