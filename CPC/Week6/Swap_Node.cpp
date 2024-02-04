#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    void correctBSTUtil(Node* root, Node*& prev, Node*& first, Node*& second) {
        if (!root) return;
        correctBSTUtil(root->left, prev, first, second);
        if (prev && root->data < prev->data) {
            if (!first) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        correctBSTUtil(root->right, prev, first, second);
    }
    
    Node* correctBST(Node* root) {
        Node* first = NULL;
        Node* second = NULL;
        Node* prev = NULL;
        correctBSTUtil(root, prev, first, second);
        if (first && second) {
            swap(first->data, second->data);
        }
        return root;
    }
};

int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string s;
        getline(cin, s);

        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);

        Solution ob;
        root = ob.correctBST(root);

        if (!isBST(root, INT_MIN, INT_MAX)) {
            cout << "0\n";
            continue;
        }

        vector<pair<int, int>> mismatch;
        if (!compare(root, duplicate, mismatch)) {
            cout << "0\n";
            continue;
        }

        if (mismatch.size() != 2 || mismatch[0].first != mismatch[1].second ||
            mismatch[0].second != mismatch[1].first)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}
