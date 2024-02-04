#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

class Solution {
public:
    bool check(Node *root) {
        if (root == nullptr)
            return true;

        queue<Node*> q;
        q.push(root);
        int leafLevel = -1;

        while (!q.empty()) {
            int size = q.size();
            bool hasLeaf = false;

            while (size--) {
                Node* node = q.front();
                q.pop();

                if (node->left == nullptr && node->right == nullptr) {
                    if (leafLevel == -1) {
                        leafLevel = node->data;
                    } else {
                        if (node->data != leafLevel)
                            return false;
                    }
                    hasLeaf = true;
                }

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (hasLeaf && !q.empty())
                leafLevel = -1;
        }

        return true;
    }
};

int main() {
    Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    Solution obj1;
    cout << "Test Case 1: " << obj1.check(root1) << endl;

    Node* root2 = newNode(10);
    root2->left = newNode(20);
    root2->right = newNode(30);
    root2->left->left = newNode(10);
    root2->left->right = newNode(15);
    Solution obj2;
    cout << "Test Case 2: " << obj2.check(root2) << endl;

    delete root1->left;
    delete root1->right;
    delete root1;
    delete root2->left->left;
    delete root2->left->right;
    delete root2->left;
    delete root2->right;
    delete
