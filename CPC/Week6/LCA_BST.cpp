#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    Node* LCA(Node* root, int n1, int n2) {
        if (root == nullptr)
            return nullptr;

        if (root->data > n1 && root->data > n2)
            return LCA(root->left, n1, n2);

        if (root->data < n1 && root->data < n2)
            return LCA(root->right, n1, n2);

        return root;
    }
};

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return nullptr;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        int l, h;
        getline(cin, s);
        cin >> l >> h;
        cin.ignore();
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, l, h)->data;
        cout << ans << endl;
    }
    return 0;
}
